%token NUMBER IDENTIFIER

%%

program : NUMBER
        ;


%%


int main(int argc, char* argv[])
{
    yyparse();
    return 0;
}