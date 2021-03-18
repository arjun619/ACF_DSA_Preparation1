
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        
        if(head == NULL){
            return NULL;
        }
        int c=0;
        node *temp,*curr=NULL,*nxt=head;
        while(c<k && nxt){
            temp = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = temp;
            c++;
        }
        
        head->next = reverse(temp,k);
        head = curr;
        
        return head;
    }
};
