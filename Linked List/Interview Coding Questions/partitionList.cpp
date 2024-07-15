void partitionList(int x) {
            if (head == nullptr) return;
 
            Node dummy1(0);
            Node dummy2(0);
            Node* prev1 = &dummy1;
            Node* prev2 = &dummy2;
            Node* current = head;
 
            while (current != nullptr) {
                if (current->value < x) {
                    prev1->next = current;
                    prev1 = current;
                } else {
                    prev2->next = current;
                    prev2 = current;
                }
                current = current->next;
            }
 
            prev2->next = nullptr;
            prev1->next = dummy2.next;
            head = dummy1.next;
        }