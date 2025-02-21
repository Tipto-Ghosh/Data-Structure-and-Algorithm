public class BasicsLL {
  
    public static class Node{
      int data; // Value
      Node next; // Address of next Node
      Node(int data){
        this.data = data;
      }
    }

    public static void main(String[] args) {
        Node a = new Node(0);
        Node b = new Node(10);
        Node c = new Node(20);
        Node d = new Node(30);
        Node e = new Node(40);

        //Connect a->b->c->d->e
        // 0 10 20 30 40
        a.next = b;// 0 -> 10 20 30 40
        b.next = c;// 0 -> 10-> 20 30 40
        c.next = d;// 0 -> 10-> 20 -> 30 40
        d.next = e;// 0 -> 10-> 20 -> 30-> 40
       // System.out.println(((((a.next).next).next).next).data); // a.next = b -->((a.next).next) = c -->((a.next).next).next = d --> ((((a.next).next).next).next) = e
        // The ans will be the data of e; which is 40 

       // System.out.println(a.next.next.data); // a.next = b; a.next.next = c; a.next.next.data = value of c

        // Print a LinedList when just the head is given:
        // System.out.println("Print a LinedList when just the head is given:");
        // Node temp = a;
        // for(int i = 0; i <= 5; i++){
        //    System.out.print(temp.data + "-->");
        //    temp = temp.next;
        // }
        System.out.println();
        System.out.print("Print it again:");
        System.out.println();
        
        // for(Node temp2 = a; temp2 != null; temp2 = temp2.next){
        //     System.out.print(temp2.data + "-->");
        // }    
        
        // System.out.println();
        // // Using while loop
        // Node temp3 = a;

        // while(temp3 != null){
        //     System.out.println(temp3.data);
        //     temp3 = temp3.next;
        // }

       // Display Linked List using recursion
        // printLinkedList(a);
        // System.out.println();   
        // printLinkedListUsingRecursion(a);
        // System.out.println();
        // displayR(a);
        int lengthByIterative = findLengthOfLinkedListIterative(a);
        System.out.println(lengthByIterative);

        int length = findLengthOfLinkedListRecursion(a);
        System.out.println(length);
    }

    // Display Linked List using function
    private static void printLinkedList(Node head){
        // while (head.next != null){
        //     System.out.println(head.data);
        //     head = head.next;
        // }

        while (true) {
            System.out.println(head.data);
            if(head.next == null){
                break;
            }
            head = head.next;
        }
    }

    // Display Linked List using Recursion
    private static void printLinkedListUsingRecursion(Node a){
        
        // Operation
        System.out.print(a.data + " ");
         // Base Case
         if(a.next == null){
            return;
        }
        // Updation
        a = a.next;
        
        // Repeat the call
        printLinkedListUsingRecursion(a);
    }

    private static void displayR(Node head){
        // Base Case
        if(head == null) return;

        System.out.print(head.data + " ");
        displayR(head.next);
    }

    // Create a method to find the length of a linked list[iterative]
      private static int findLengthOfLinkedListIterative(Node head) {
         int count = 0;
         while (head != null) {
            count++;
            head = head.next;
         }
         return count;
      }
    // Create a method to find the length of a linked list[Recursion]
    private static int findLengthOfLinkedListRecursion(Node head) {
    
        // Base Case:
        if(head == null) return 0;
        
        // Updation
        head = head.next;
        //Repeat the call
        return 1 + findLengthOfLinkedListRecursion(head);
    }
}