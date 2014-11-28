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
	V remove(V);
	void clear();

	bool containsKey(K);
	int size();

	void toArray(V[]);
	
private:
	int n = 0;

	K keys[MAXSIZE];
	V values[MAXSIZE];

	V removeIndex(int);
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
	for (int i = 0; i < n; ++i){
		// Look for keys
		if(keys[i] == key){
			value = removeIndex(i);
			break;
		}
	}

	return value;
}

template <typename K, typename V>
V Map<K,V>::remove(V value){
	V val = NULL;
	for (int i = 0; i < n; ++i){
		// Look for keys
		if(values[i] == value){
			val = removeIndex(i);
			break;
		}
	}

	return val;
}

template <typename K, typename V>
V Map<K,V>::removeIndex(int i){
	V value = values[i];

	for (i = i+1; i < n; ++i){
		// Shift everything back
		values[i-1] = values[i];
		keys[i-1] = keys[i];
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
}