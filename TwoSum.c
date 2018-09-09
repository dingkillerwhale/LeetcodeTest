#include <stdio.h>
#include <math.h>

int* twoSum(int* nums, int numsSize, int target);

// Define hash node
typedef struct HashNode {
	int key;
	int val;
} HashNode;
// Define hash map
typedef struct HashMap {
	int size;
	HashNode**storage; // a pointer storage which points to a Hashnode pointer
} HashMap;

HashMap* hash_create(int size);// a function return a pointer which point to HashMap
void hash_destroy(HashMap* hashMap); // a function with the HashMap pointer
void hash_set(HashMap* hashMap, int key, int value); // set Hash map
HashNode* hash_get(HashMap* hashMap, int key); // search Hash map

HashMap* hash_create(int size) {
	HashMap* hashMap = malloc(sizeof(HashMap));
	hashMap->size = size;
	hashMap->storage = calloc(size, sizeof(HashNode*)); // set an array of all Hash note pointer
	return hashMap;
}
// release the space of hash map
void hash_destroy(HashMap* hashMap) {
	for (int i = 0; i < hashMap->size; i++) {
		HashNode* Node;
		if ((Node = hashMap-> storage[i])) {
			free(Node);
		}
	}
	free(hashMap->storage);
	free(hashMap);
}

void hash_set(HashMap *hashMap, int key, int value) {
	int hash = abs(key) % hashMap->size;
	HashNode* Node;
	while ((Node = hashMap->storage[hash])) {
		if (hash < hashMap->size - 1) {
			hash++;
		}
		else {
			hash = 0;
		}
	}
	Node = malloc(sizeof(HashNode));
	Node->key = key;
	Node->val = value;
	hashMap->storage[hash] = Node;
}

HashNode* hash_get(HashMap *hashMap, int key) {
	int hash = abs(key) % hashMap->size;
	HashNode* Node;
	while ((Node = hashMap->storage[hash])) {
		if ((Node->key == key)) {
			return Node;
		}
		if (hash < hashMap->size - 1) {
			hash++;
		}
		else {
			hash = 0;
		}
	}
	return NULL;
}


int* twoSum(int* nums, int numsSize, int target) {
	HashMap* hashMap; // Hash map pointer
	HashNode* Node; // Hash node pointer
	int rest, i;

	//make the Hash map 2x size of the numsSize
	hashMap = hash_create(numsSize * 2); //create a hash map
	for (i = 0; i < numsSize; i++) {
		rest = target - nums[i];
		Node = hash_get(hashMap, rest); // chech if the given num in the current hash map
		if (Node) { // if locate the given num
			int* result = malloc(sizeof(int) * 2);
			result[0] = Node->val;
			result[1] = i;
			hash_destroy(hashMap);
			return result;
		}
		else {
			hash_set(hashMap, nums[i], i); // fill the hash map
		}
	}
	return NULL;
}


void main(void) {

	int Given_Nums[] = { 2,7,11,15 }, target = 9;
	int Size = sizeof(Given_Nums) / sizeof(Given_Nums[0]);
	int *Sum;

	Sum = twoSum(Given_Nums, Size, target);
	printf("%d, %d", Sum[0], Sum[1]);
	
	return 0;
}