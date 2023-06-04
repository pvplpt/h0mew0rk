/*
* Реализовать класс работающий по принципу HashMap. 
* Включая внутренний массив узлов с индексацией по хешу и описание узла. 
* Добавить в класс методы:
*   Object put(Integer key , Integer value) добавить элемент
*   Object get(Integer key) получить значение соответствующее ключу
*   Object remove(Integer key) удалить элемент с соответствующем ключём
*   Object replays(Integer key, Integer v) заменить значение
*   int size() количество элементов
*   boolean containsKey(Integer key) проверка наличия ключа и значения
*   boolean containsValue(Integer v)
 */

public class Program4 {
    Node[] hashTable = new Node[16];
    int size = 0;

    // public static void main(String[] args) {

    // Program4 myHashMap = new Program4();

    // for (Integer i = 0; i < 32; i++) {
    // myHashMap.put(i + 1, i);
    // }
    // System.out.println(myHashMap.size());
    // System.out.println(myHashMap.get(30));
    // System.out.println(myHashMap.remove(30));
    // System.out.println(myHashMap.size());
    // System.out.println(myHashMap.get(20));
    // System.out.println(myHashMap.replays(20, 123));
    // System.out.println(myHashMap.get(20));
    // System.out.println(myHashMap.containsKey(30));
    // System.out.println(myHashMap.containsKey(20));
    // System.out.println(myHashMap.containsValue(123));
    // System.out.println(myHashMap.containsValue(321));
    // }

    public Object put(Integer key, Integer value) {
        Node temp = new Node();
        temp.key = key;
        temp.hash = temp.key.hashCode() % 16;
        temp.value = value;
        if (hashTable[temp.hash] != null) {
            Node tempNode = hashTable[temp.hash];
            while (tempNode != null) {
                if (tempNode.key == key) {
                    return tempNode.value;
                }
                tempNode = tempNode.next;
            }
            temp.next = hashTable[temp.hash];
        }
        hashTable[temp.hash] = temp;
        size++;
        return null;
    }

    public Object get(Integer key) {
        int index = key.hashCode() % 16;
        if (hashTable[index] != null) {
            Node tempNode = hashTable[index];
            while (tempNode != null) {
                if (tempNode.key == key) {
                    return tempNode.value;
                }
                tempNode = tempNode.next;
            }
        }
        return null;
    }

    public Object remove(Integer key) {
        int index = key.hashCode() % 16;
        if (hashTable[index] != null) {
            Node tempNode = hashTable[index];
            if (tempNode.key == key && tempNode.next == null) {
                hashTable[index] = null;
                size--;
                return tempNode.value;
            }
            if (tempNode.key == key && tempNode.next != null) {
                hashTable[index] = tempNode.next;
                size--;
                return tempNode.value;
            }
            while (tempNode.next != null) {
                if (tempNode.next.key == key) {
                    Integer tmp = tempNode.next.value;
                    tempNode.next = tempNode.next.next;
                    size--;
                    return tmp;
                }
                tempNode = tempNode.next;
            }
        }
        return null;
    }

    public Object replays(Integer key, Integer v) {
        int index = key.hashCode() % 16;
        if (hashTable[index] != null) {
            Node tempNode = hashTable[index];
            while (tempNode != null) {
                if (tempNode.key == key) {
                    Integer x = tempNode.value;
                    tempNode.value = v;
                    return x;
                }
                tempNode = tempNode.next;
            }
        }
        return null;
    }

    public int size() {
        return size;
    }

    public boolean containsKey(Integer key) {
        return get(key) != null;

    }

    public boolean containsValue(Integer v) {
        if (size > 0) {
            for (int i = 0; i < hashTable.length; i++) {
                if (hashTable[i] != null) {
                    Node tempNode = hashTable[i];
                    while (tempNode != null) {
                        if (tempNode.value == v) {
                            return true;
                        }
                        tempNode = tempNode.next;
                    }

                }

            }

        }
        return false;
    }
}

class Node {
    int hash;
    Integer key;
    Integer value;
    Node next;
}