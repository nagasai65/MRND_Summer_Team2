struct node
{
	char data;
	node* next;
};
node* createlist(char *arr, int k);
node* reverse(node* head);
node *foo(int k, node* head);
void testswapknodes();
