#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>

struct AdjListNode 
{ 
	int dest; 
	long long int weight; 
	struct AdjListNode* next; 
}; 

// A structure to represent an adjacency list 
struct AdjList 
{ 
	struct AdjListNode *head; // pointer to head node of list 
}; 

struct Graph 
{ 
	int V; 
	struct AdjList* array; 
}; 

struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
	struct AdjListNode* newNode = 
			(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->weight = weight; 
	newNode->next = NULL; 
	return newNode; 
} 

struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V; 

	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 

	for (int i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
	
	struct AdjListNode* newNode = newAdjListNode(dest, weight); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	newNode = newAdjListNode(src, weight); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 

struct MinHeapNode 
{ 
	int v; 
	int dist; 
}; 

struct MinHeap 
{ 
	int size;	 
	int capacity; 
	int *pos;	 
	struct MinHeapNode **array; 
}; 

struct MinHeapNode* newMinHeapNode(int v, int dist) 
{ 
	struct MinHeapNode* minHeapNode = 
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode)); 
	minHeapNode->v = v; 
	minHeapNode->dist = dist; 
	return minHeapNode; 
} 

struct MinHeap* createMinHeap(int capacity) 
{ 
	struct MinHeap* minHeap = 
		(struct MinHeap*) malloc(sizeof(struct MinHeap)); 
	minHeap->pos = (int *)malloc(capacity * sizeof(int)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array = 
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
	int smallest, left, right; 
	smallest = idx; 
	left = 2 * idx + 1; 
	right = 2 * idx + 2; 

	if (left < minHeap->size && 
		minHeap->array[left]->dist < minHeap->array[smallest]->dist ) 
	smallest = left; 

	if (right < minHeap->size && 
		minHeap->array[right]->dist < minHeap->array[smallest]->dist ) 
	smallest = right; 

	if (smallest != idx) 
	{ 
		// The nodes to be swapped in min heap 
		struct MinHeapNode *smallestNode = minHeap->array[smallest]; 
		struct MinHeapNode *idxNode = minHeap->array[idx]; 

		// Swap positions 
		minHeap->pos[smallestNode->v] = idx; 
		minHeap->pos[idxNode->v] = smallest; 

		// Swap nodes 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 

		minHeapify(minHeap, smallest); 
	} 
} 

int isEmpty(struct MinHeap* minHeap) 
{ 
	return minHeap->size == 0; 
} 

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	if (isEmpty(minHeap)) 
		return NULL; 

	// Store the root node 
	struct MinHeapNode* root = minHeap->array[0]; 

	// Replace root node with last node 
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
	minHeap->array[0] = lastNode; 

	// Update position of last node 
	minHeap->pos[root->v] = minHeap->size-1; 
	minHeap->pos[lastNode->v] = 0; 

	// Reduce heap size and heapify root 
	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return root; 
} 

// Function to decreasy dist value of a given vertex v. This function 
// uses pos[] of min heap to get the current index of node in min heap 
void decreaseKey(struct MinHeap* minHeap, int v, int dist) 
{ 
	// Get the index of v in heap array 
	int i = minHeap->pos[v]; 

	// Get the node and update its dist value 
	minHeap->array[i]->dist = dist; 

	// Travel up while the complete tree is not hepified. 
	// This is a O(Logn) loop 
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) 
	{ 
		// Swap this node with its parent 
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2; 
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i; 
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 

		// move to parent index 
		i = (i - 1) / 2; 
	} 
} 


bool isInMinHeap(struct MinHeap *minHeap, int v) 
{ 
if (minHeap->pos[v] < minHeap->size) 
	return true; 
return false; 
} 


void dijkstra(struct Graph* graph, int centers[],long long int dist[],int K) 
{ 
	int V = graph->V;// Get the number of vertices in graph 
	bool visited[V];
	// minHeap represents set E 
	struct MinHeap* minHeap = createMinHeap(V); 

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v) 
	{ 
		dist[v] = INT_MAX; 
		minHeap->array[v] = newMinHeapNode(v, dist[v]); 
		minHeap->pos[v] = v; 
		visited[V]=false;
	} 

	// Make dist value of src vertex as 0 so that it is extracted first 
    for(int i=0;i<K;i++)
    {
	    minHeap->array[centers[i]-1] = newMinHeapNode(centers[i]-1, dist[centers[i]-1]); 
	    minHeap->pos[centers[i]-1] = centers[i]-1; 
	    dist[centers[i]-1] = 0; 
	    decreaseKey(minHeap, centers[i]-1, dist[centers[i]-1]); 
    }

	// Initially size of min heap is equal to V 
	minHeap->size = V; 

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap)) 
	{ 
		// Extract the vertex with minimum distance value 
		struct MinHeapNode* minHeapNode = extractMin(minHeap); 
		int u = minHeapNode->v; // Store the extracted vertex number 
		if(visited[u]==true) continue;
		visited[u]=true;
		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) 
		{ 
			int v = pCrawl->dest; 

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (pCrawl->weight + dist[u] < dist[v]) 
			{ 
				dist[v] = dist[u] + pCrawl->weight; 

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]); 
			} 
			pCrawl = pCrawl->next; 
		} 
	} 

	// print the calculated shortest distances 
	// printArr(dist, V); 
} 


// Driver program to test above functions 
int main() 
{ 
    int N,M,K,Q,i,j;
    scanf("%d %d %d %d",&N,&M,&K,&Q);
    struct Graph* graph = createGraph(N);
    long long int dist[N]; 
    for(i=0;i<M;i++)
    {
        int U,V;
        long long int W;
        scanf("%d %d %lld",&U,&V,&W);
        addEdge(graph,U-1,V-1,W);
    }
    int centers[K-1];
    for(i=0;i<K;i++)
    {
        scanf("%d",&centers[i]);
    }
    dijkstra(graph,centers,dist,K);
    for(i=0;i<Q;i++)
    {
        int X;
        scanf("%d",&X);
        if(dist[X-1]==INT_MAX) printf("-1\n");
        else printf("%lld\n",dist[X-1]);
    }
} 
