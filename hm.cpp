#include
#include
#include
using namespace std;

struct node {
   int freq;
   char data;
   const node *child0, *child1;

   node(char d, int f = -1) { //оценка значений в этом узле
      data = d;
      freq = f;
      child0 = NULL;
      child1 = NULL;
   }

   node(const node *c0, const node *c1) {
      data = 0;
      freq = c0->freq + c1->freq;
      child0=c0;
      child1=c1;
   }

   bool operator<( const node &a ) const { //< выполнение приоритета в очереди
      return freq >a.freq;
   }

   void traverse(string code = "")const {
      if(child0!=NULL) {
         child0->traverse(code+'0'); //добавление о в левой ветки(ребенка)
         child1->traverse(code+'1'); //добавление 1 в правой части
      }else {
         cout << "Data: " << data<< ", Frequency: "< qu;
   int frequency[256];

   for(int i = 0; i<256; i++)
      frequency[i] = 0; //очистить все

   for(int i = 0; i1) {
      node *c0 = new node(qu.top()); //полусение левого и возращение в очередь
      qu.pop();
      node *c1 = new node(qu.top()); //получение правого и возращение в очередь
      qu.pop();
      qu.push(node(c0, c1));
   }

