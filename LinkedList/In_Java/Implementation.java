public class Implementation {

      public static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
         }
      }
      public static class linkedList{
           Node head = null;
           Node tail = null;
           int size = 0;

           void insertAtEnd(int data){
             Node temp = new Node(data);  
             // if linked list is empty
              if(head == null){
                 head = temp;
     
              }
              else{
                 tail.next = temp;
              }
              tail = temp;
              size++;
           }

           // Insert at the begging
           void insetAtBeginning(int data){

              Node temp = new Node(data);
              
              if(head == null){ // If there is no element:
                head = temp;
              }
              else{
                 temp.next = head;
              }
              head = temp;
              size++;
            }

           // Create a function that add elements at givien index of a linked list
           void addAtGivenIndex(int data , int position){
              Node temp = new Node(data);
              
              // Handle the proper position
              if(position < 0 || position > size){
                 throw new IndexOutOfBoundsException("Invalid Position");
               }
              // If position is 0[at the first position]
              if(position == 0){
                temp.next = head;
                head = temp;
                size++;
                return;
              }

              // If Another Cases :
              Node t = head; // save the head postion traverse at the index that is given
              for(int i = 0; i < position -1; i++){
                t = t.next;
              }

              temp.next = t.next;
              t.next = temp;
              size++;
            }
            // Delete a element of a linked list
            void deleteAt(int index){
              
               if(index < 0 || index > size){
                  throw new IndexOutOfBoundsException("Invalid Index");
               }
               // If dete at fost index
               if(index == 0){
                  head = head.next;
                  size--;
                  return;
               }
               Node temp = head;
               for(int i = 1; i < index; i++){
                   temp = temp.next;
               }

               temp.next = temp.next.next;
               tail = temp;
               size--;
            }
           // Display the linked list
           void display(){
             Node temp = head;
              while (temp != null) {
                 System.out.print(temp.data + " ");
                 temp = temp.next;
              }
           }

           // Find the length of a linked list
           int size(){
              int count = 0;
              Node temp = head;
              while (temp != null) {
                 count ++;
                 temp = temp.next;
              }
              return count;
           }

           // Get a value of given index
           int getValue(int index){
             if(index < 0 || index > size){
               System.out.println("Invlid Index");
               return -1;
             }

             Node temp = head;
             for(int i = 0; i < index; i++){
                temp = temp.next;
             }

             return temp.data;
           }
        }
    
    public static void main(String[] args) {
         //  linkedList ll = new linkedList();
         //  ll.insertAtEnd(0);
         //  ll.insertAtEnd(1);
         //  ll.insertAtEnd(2);
         //  ll.insertAtEnd(3);
         //  ll.insertAtEnd(4);
         //  ll.insertAtEnd(5);
         //  ll.insertAtEnd(20);
         //  ll.addAtGivenIndex(1000, 0);
         
         //  System.out.println();
         //  ll.display();
         //  System.out.println();

         // ll.deleteAt(0);
         // ll.display();
         //  System.out.println();


         //  ll.deleteAt(3);
         // ll.display();
         //  System.out.println();



         //  System.out.println(ll.getValue(0)); 
         //  System.out.println();
         //  System.out.println(ll.size);
         //  ll.addAtGivenIndex(1000, 4);
         //  System.out.println();
         //  ll.display();
         //  ll.insetAtBeginning(-20);

         //  ll.display();
         //  System.out.println();
         //  ll.addAtGivenIndex(50, 2);
         //  ll.addAtGivenIndex(99, 4);
         //  System.out.println();
         //  ll.display();

         //  System.out.println();
         //  ll.addAtGivenIndex(500, 3);
         //  System.out.println();
         //  ll.display();
        //   System.out.println(ll.size());

        //  linkedList ll2 = new linkedList();
        //  ll2.insetAtBeginning(49); 
        //  ll2.display();
        //  System.out.println();
        //  System.out.println(ll2.size());


        linkedList l2 = new linkedList();
        l2.insertAtEnd(0); // 0
        l2.addAtGivenIndex(1, 1); // 0->1
        l2.insetAtBeginning(5);// 5->0->1
        l2.display();// 5 0 1
        System.out.println();
        l2.deleteAt(1); // 5->1
        l2.display();
        l2.deleteAt(1);
        System.out.println();
        l2.display();
    }
}