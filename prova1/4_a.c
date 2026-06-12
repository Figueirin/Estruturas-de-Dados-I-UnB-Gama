Produto *produtos =(Produto*) malloc(n *sizeof (Produto)) ;

if (produtos == NULL) {
printf ("Erro ao alocar memoria \n") ;
return 1;
}

for (int i = 0; i < n ; i++) {
printf ("Nome: ") ;
scanf ( "%49s " ,produtos[i].nome);
printf ("Preco: ") ;
scanf ( "%f" , &produtos[i].preco);
printf ("Quantidade: ");
scanf ("%d " ,&produtos [i].quantidade);
}

free(produtos);
return 0;