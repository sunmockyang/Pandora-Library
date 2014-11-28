#ifndef MAP_H
#define MAP_H

#define MAXSIZE 1024
#define NULL 0

template <typename K, typename V>
class Map
{
public:
	Map<K,V>();
	Map<K,V>(Map<K,V>&);
	void add(K, V);
	V find(K);
	V remove(K);
	void clear();

	bool containsKey(K);
	int size();

	void toArray(V[]);
	
private:
	int n = 0;

	K keys[MAXSIZE];
	V values[MAXSIZE];
};

#endif

template <typename K, typename V>
Map<K,V>::Map(){}

template <typename K, typename V>
Map<K,V>::Map(Map<K,V>& old){
	n = old.size();
	for (int i = 0; i < n; ++i){
		keys[i] = old.keys[i];
		values[i] = old.values[i];
	}
}

template <typename K, typename V>
void Map<K,V>::add(K key, V value){
	keys[n] = key;
	values[n] = value;

	n++;
}

template <typename K, typename V>
V Map<K,V>::find(K key){
	for (int i = 0; i < n; ++i)
	{
		if(keys[i] == key){
			return values[i];
		}
	}
	return NULL;
}

template <typename K, typename V>
V Map<K,V>::remove(K key){
	V value = NULL;
	int i;
	for (i = 0; i < n; ++i){
		// Look for keys
		if(value == NULL){
			if(keys[i] == key){
				value = values[i];
			}
		}
		// Shift everything back
		else{
			values[i-1] = values[i];
			keys[i-1] = keys[i];
		}
	}

	// Unnecessary but don't want dangling pointers
	if (value != NULL){
		values[--n] = NULL;
		keys[n] = NULL;
	}

	return value;
}

template <typename K, typename V>
void Map<K,V>::clear(){
	for (int i = 0; i < n; ++i)
	{
		keys[i] = NULL;
		values[i] = NULL;
	}
	n = 0;
}

template <typename K, typename V>
bool Map<K,V>::containsKey(K key){
	return (find(key) != NULL) ? true : false;
}

template <typename K, typename V>
int Map<K,V>::size(){ return n; }

template <typename K, typename V>
void Map<K,V>::toArray(V v[]){
	for (int i = 0; i < n; ++i)
	{
		v[i] = values[i];
	}
	// return values;
}