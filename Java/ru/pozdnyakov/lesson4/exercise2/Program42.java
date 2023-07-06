package ru.pozdnyakov.lesson4.exercise2;
/*
 * Задание 2*. Реализуйте очередь с помощью LinkedList со следующими методами:
 * enqueue() - помещает элемент в конец очереди,
 * dequeue() - возвращает первый элемент из очереди и удаляет его,
 * first() - возвращает первый элемент из очереди, не удаляя.
 * Это задание повышенной сложности, 
 * для решения задачи потребуется создать класс-обертку над LinkedList, 
 * например:
 * 
 * class MyQueue {
 *     private LinkedList elements = new LinkedList();
 * 
 *     public MyQueue() { }
 *     public MyQueue(LinkedList linkedList) {
 *         this.elements = linkedList;
 *     }
 * 
 *         .........
 * 
 * }
 */


public class Program42 {
    public static void main(String[] args) {
        task2();
    }

    public static void task2() {
        MyQueue myQueue = new MyQueue();
        System.out.println("\nОчередь при открытии магазина:");
        myQueue.printMyQueue();
        myQueue.enqueue("Покупатель1");
        myQueue.enqueue("Покупатель2");
        myQueue.enqueue("Покупатель3");
        myQueue.enqueue("Покупатель4");     
        myQueue.enqueue("Покупатель5");    
        System.out.println("\nОчередь через 20 минут:");        
        myQueue.printMyQueue();
        System.out.printf("\nРасплатился %s\n",myQueue.dequeue());
        System.out.println("\nОстались:");
        myQueue.printMyQueue();
        System.out.printf("\nПервый в оереди %s\n",myQueue.first());
        System.out.printf("\nРасплатился %s\n",myQueue.dequeue());
        System.out.println("\nОстались:");
        myQueue.printMyQueue();
    }
}
