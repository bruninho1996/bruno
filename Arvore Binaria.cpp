#include <stdio.h>
#include <stdlib.h>
/*Bruno Tavares Almeida*/

typedef struct tree

{

  int num;

  struct tree* sad;

  struct tree* sae;

} Tree;

/* Função que cria uma árvore */

Tree* createTree()

{


  return NULL;

}


int treeIsEmpty(Tree* t)

{


  return t == NULL;



}





void showTree(Tree* t)

{

  
  

  printf("<"); 

  if(!treeIsEmpty(t)) 

  {

    
    printf("%d ", t->num); 

    showTree(t->sae); 

    showTree(t->sad); 

  }

  printf(">"); 

}

void insertTree(Tree** t, int num)

{

  if(*t == NULL)

  {

    *t = (Tree*)malloc(sizeof(Tree)); 

(*t)->sae = NULL; 
(*t)->sad = NULL; 
(*t)->num = num; 

  } else {

    if(num < (*t)->num) 
    {

      

      insertTree(&(*t)->sae, num);

    }

    if(num > (*t)->num) 

{
insertTree(&(*t)->sad, num);
}

  }

}





int isInTree(Tree* t, int num) {

  

  if(treeIsEmpty(t)) { 

    return 0;

  }
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);

}



int main()

{

  Tree* t = createTree(); 

  

  insertTree(&t, 21); 

  insertTree(&t, 18); 

  insertTree(&t, 89); 

  insertTree(&t, 40); 

   

  showTree(t); 

  

  if(treeIsEmpty(t)) 

  {

    printf("\n\nArvore vazia!!\n");

  } else {

    printf("\n\nArvore NAO vazia!!\n");

  }

  

  if(isInTree(t, 21)) { 

    printf("\nO numero 21 pertence a arvore!\n");

  } else {

     printf("\nO numero 21 NAO pertence a arvore!\n");

  }

  

  if(isInTree(t,30)) { /* Verifica se o número 30 pertence a árvore */

    printf("\nO numero 30 pertence a arvore!\n\n");

  } else {

     printf("\nO numero 30 NAO pertence a arvore!\n\n");

  }

  

  free(t); 

  

  return 0;

}

