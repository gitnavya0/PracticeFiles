//   +======================================================+
//   | Description:                                         |
//   | - Check if the linked list has a loop                |
//   | - Return type: bool                                  |
//   |                                                      |
//   | Tips:                                                |
//   | - Use two pointers: 'slow' and 'fast'                |
//   | - 'slow' moves one step, 'fast' moves two            |
//   | - If they meet, a loop exists                        |
//   | - Return true if loop found, false otherwise         |
//   | - 'fast' checks for null and its 'next' for null     |
//   +======================================================+

//Floyd's cycle-finding algorithm 
//(also known as the "tortoise and the hare" algorithm) 

bool hasLoop(){
            Node* fast = head;
            Node* slow = head;
            
            while(fast != nullptr && fast->next != nullptr){
                slow=slow->next;
                fast=fast->next->next;
                if(fast==slow){
                    return true;
                }
            }
            return false;
        }