## Урок 4. Хранение и обработка данных ч1: приоритетные коллекции

> Формат сдачи: ссылка на подписанный git-проект.

### **Задание**

### **1. Пусть дан LinkedList с несколькими элементами. Реализуйте метод, который вернет “перевернутый” список.**
```
```
### **2** * **. Реализуйте очередь с помощью LinkedList со следующими методами:**
### **enqueue() - помещает элемент в конец очереди,**
### **dequeue() - возвращает первый элемент из очереди и удаляет его,**
### **first() - возвращает первый элемент из очереди, не удаляя.**
### **Это задание повышенной сложности, для решения задачи потребуется создать класс-обертку над LinkedList, например:**
```
class MyQueue {
    private LinkedList elements = new LinkedList();

    public MyQueue() { }
    public MyQueue(LinkedList linkedList) {
        this.elements = linkedList;
    }

        .........

}
```
### **3. В калькулятор (урок 1 и 2) добавьте возможность отменить последнюю операцию.**
```
```
> Формат сдачи: файл с расширением java или ссылка на гит с подписанными ФИ и номером группы.