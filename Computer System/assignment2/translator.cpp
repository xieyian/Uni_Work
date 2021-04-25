// convert a document tree into VM code
#include "iobuffer.h"
#include "abstract-syntax-tree.h"
#include "assembler-internal.h"

// to make out programs a bit neater
using namespace std ;

using namespace CS_IO_Buffers ;
using namespace Hack_Virtual_Machine ;
string funcname;
string funcname2;
int check=0;
// grammer to be parsed:
// vm_class ::= command* eoi
// command ::= vm_operator | vm_jump | vm_func | vm_stack
// vm_operator ::= 'add' | 'and' | 'eq' | 'gt' | 'lt' | 'neg' | 'not' | 'or' | 'sub' | 'return'
// vm_jump ::= jump label
// vm_func ::= func label number
// vm_stack ::= stack segment number

// forward declare parsing functions - one per rule
static void translate_vm_class(ast root) ;
static void translate_vm_command(ast command) ;
static void translate_vm_operator(ast vm_op) ;
static void translate_vm_jump(ast jump) ;
static void translate_vm_func(ast func) ;
static void translate_vm_stack(ast stack) ;

////////////////////////////////////////////////////////////////

/************   PUT YOUR HELPER FUNCTIONS HERE   **************/
void push(string method){
    output_assembler(method);
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("A=M");
    output_assembler("M=D");
    output_assembler("@SP");
    output_assembler("M=M+1");
}

void push1(string method,string name){
    output_assembler(method);
    output_assembler("D=A");
    output_assembler(name);
    output_assembler("A=D+M");
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("A=M");
    output_assembler("M=D");
    output_assembler("@SP");
    output_assembler("M=M+1");

}

void helpFunc1(string value1, string value2){
    output_assembler(value1);
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler(value2);
    output_assembler("M=D");
}




/************      END OF HELPER FUNCTIONS       **************/

///////////////////////////////////////////////////////////////



// the function translate_vm_class() will be called by the main program
// its is passed the abstract syntax tree constructed by the parser
// it walks the abstract syntax tree and produces the equivalent VM code as output
static void translate_vm_class(ast root)
{
    // assumes we have a "class" node containing VM command nodes
    ast_mustbe_kind(root,ast_vm_class) ;

    // tell the output system we are starting to translate VM commands for a Jack class
    start_of_vm_class() ;

    int ncommands = size_of_vm_class(root) ;
    for ( int i = 0 ; i < ncommands ; i++ )
    {
        translate_vm_command(get_vm_class(root,i)) ;
    }

    // tell the output system we have just finished translating VM commands for a Jack class
    end_of_vm_class() ;

}

// translate the current vm command - a bad node is a fatal error
static void translate_vm_command(ast command)
{
    switch(ast_node_kind(command))
    {
    case ast_vm_operator:
        translate_vm_operator(command) ;
        break ;
    case ast_vm_jump:
        translate_vm_jump(command) ;
        break ;
    case ast_vm_function:
        translate_vm_func(command) ;
        break ;
    case ast_vm_stack:
        translate_vm_stack(command) ;
        break ;
    default:
        fatal_error(0,"// bad node - expected vm_operator, vm_jump, vm_function or vm_stack\n") ;
        break ;
    }
}

// translate vm operator command into assembly language
static void translate_vm_operator(ast vm_op)
{
    // extract command specific info from the ast node passed in
    string the_op = get_vm_operator_command(vm_op) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_operator_command(the_op) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    if(the_op=="add"){
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("M=D+M");
        output_assembler("@SP");
        output_assembler("M=M+1");

    }else if(the_op=="sub"){
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("M=M-D");
        output_assembler("@SP");
        output_assembler("M=M+1");

    }else if(the_op=="neg"){
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("D=M");
        output_assembler("M=-D");

    }else if(the_op=="and"){
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("M=D&M");
        output_assembler("@SP");
        output_assembler("M=M+1");

    }else if(the_op=="or"){
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("M=M-1");
        output_assembler("A=M");
        output_assembler("M=D|M");
        output_assembler("@SP");
        output_assembler("M=M+1");

    }else if(the_op=="not"){
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("D=M");
        output_assembler("M=!D");

    }else if(the_op=="eq"){


    }else if(the_op=="gt"){
        
    }else if(the_op=="lt"){
        
    }else if(the_op=="return"){
    output_assembler("@LCL");
    output_assembler("D=M");
    output_assembler("@R13");
    output_assembler("M=D");

    output_assembler("@5");
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler("@R14");
    output_assembler("M=D");

    output_assembler("@SP");
    output_assembler("A=M-1");
    output_assembler("D=M");
    output_assembler("@ARG");
    output_assembler("A=M");
    output_assembler("M=D");

    output_assembler("@ARG");
    output_assembler("M=M+1");
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("M=D");

    output_assembler("@1");
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler("@THAT");
    output_assembler("M=D");

    output_assembler("@2");
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler("@THIS");
    output_assembler("M=D");

    output_assembler("@3");
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler("@ARG");
    output_assembler("M=D");

    output_assembler("@4");
    output_assembler("D=A");
    output_assembler("@R13");
    output_assembler("A=M-D");
    output_assembler("D=M");
    output_assembler("@LCL");
    output_assembler("M=D");

    output_assembler("@R14");
    output_assembler("A=M");
    output_assembler("0;JMP");

}

        
 


    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_jump(ast jump)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_jump_command(jump) ;
    string label = get_vm_jump_label(jump) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_jump_command(command,label) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...


    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_func(ast func)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_function_command(func) ;
    string label = get_vm_function_label(func) ;
    int number = get_vm_function_number(func) ;
    funcname=label;
    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_func_command(command,label,number) ;
    if(command=="function"){
        output_assembler("//"+command+" "+label+" "+to_string(number));
        output_assembler("("+label+")");

        //output_assembler();
        for(int i=0;i<number;i++){
            output_assembler("@SP");
            output_assembler("A=M");
            output_assembler("M=0");
            output_assembler("@SP");
            output_assembler("M=M+1");
        }
        funcname2=label;

        

    }else if(command=="call"){

        string returnaddress="address";
        check++;
        
        output_assembler("@"+funcname2+"$"+returnaddress+to_string(check));
        output_assembler("D=A");
        output_assembler("@SP");
        output_assembler("A=M");
        output_assembler("M=D");
        output_assembler("@SP");
        output_assembler("M=M+1");
        push("@LCL");
        push("@ARG");
        push("@THIS");
        push("@THAT");

        //ARG=SP-NUMBER-5

        output_assembler("@"+to_string(number+5));
        output_assembler("D=A");
        output_assembler("@SP");
        output_assembler("D=M-D");
        output_assembler("@ARG");
        output_assembler("M=D");
        
        //LCL=SP
        output_assembler("@SP");
        output_assembler("D=M");
        output_assembler("@LCL");
        output_assembler("M=D");

        //GOTO F
        output_assembler("@"+label);
        output_assembler("0;JMP");

        //RETURN ADDRESS

 
            output_assembler("("+funcname2+"$"+returnaddress+to_string(check)+")");

    }

    /************   ADD CODE BETWEEN HERE   **************/
    

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    


    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_stack(ast stack)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_stack_command(stack) ;
    string segment = get_vm_stack_segment(stack) ;
    int number = get_vm_stack_offset(stack) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_stack_command(command,segment,number) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    if(command=="push"){
        if(segment=="constant"){
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@SP");
            output_assembler("AM=M+1");
            output_assembler("A=A-1");
            output_assembler("M=D");
        }else if(segment=="static"){
            string n="";
            for(int i=0;i<funcname.size();i++){
                if(funcname[i]!='.'){
                    n=n+funcname[i];
                }else if(funcname[i]=='.'){
                    break;
                }
            }
            output_assembler("@"+n+"."+to_string(number));
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("A=M"); 
            output_assembler("M=D");
            output_assembler("@SP");
            output_assembler("M=M+1");


        }else if(segment=="pointer"){
            
            int number1= number+3; 
            output_assembler("@"+to_string(number1));    
            output_assembler("D=M");   
            output_assembler("@SP");    
            output_assembler("A=M");
            output_assembler("M=D");
            output_assembler("@SP");
            output_assembler("M=M+1");


        }else if(segment=="this"){
            push1("@"+to_string(number), "@THIS");
        }else if(segment=="that"){
            push1("@"+to_string(number), "@THAT");
        }else if(segment=="argument"){
            push1("@"+to_string(number), "@ARG");
        }else if(segment=="temp"){
            int number1= number+5;
            output_assembler("@"+to_string(number1));    
            output_assembler("D=M");   
            output_assembler("@SP");    
            output_assembler("A=M");
            output_assembler("M=D");
            output_assembler("@SP");
            output_assembler("M=M+1");

        }else if(segment=="local"){
            push1("@"+to_string(number), "@LCL");
        }

    }else if(command=="pop"){
       if(segment=="pointer"){
           int number1=number+3;
            output_assembler("@3");
            output_assembler("D=A");    
            output_assembler("@"+to_string(number));    
            output_assembler("D=D+A");  
            output_assembler("@SP");    
            output_assembler("M=M-1");  
            output_assembler("A=M");
            output_assembler("D=M");
            output_assembler("@"+to_string(number1));
            output_assembler("M=D");

        }else if(segment=="temp"){
            int number2=number+5;
            output_assembler("@5");
            output_assembler("D=A");    
            output_assembler("@"+to_string(number));    
            output_assembler("D=D+A");  
            output_assembler("@SP");    
            output_assembler("M=M-1");  
            output_assembler("A=M");
            output_assembler("D=M");
            output_assembler("@"+to_string(number2));
            output_assembler("M=D");

        }else if(segment=="static"){
            string n;
            for(int i=0; i<funcname.size(); i++){
                n+=funcname[i];
                if(funcname[i]=='.'){
                    break;
                }
            }
            output_assembler("@SP");
            output_assembler("M=M-1");
            output_assembler("A=M");
            output_assembler("D=M");
            output_assembler("@"+n+to_string(number));
            output_assembler("M=D");

        }else if(segment=="argument"){
            output_assembler("@"+to_string(number));  // @4
            output_assembler("D=A");                  // D=4

            output_assembler("@ARG"); 
            output_assembler("D=D+M");                // D=4+RAM[1]=4+LOCAL0=LOCAL4

            output_assembler("@R13");                 //@13   
            output_assembler("M=D");                  // RAM[13]=LOCAL4

            output_assembler("@SP");                  // @0
            output_assembler("A=M-1");                // A=256 (SP POINTS TO)
            output_assembler("D=M");                  // D=RAM[256]
            output_assembler("@SP");                  // @0
            output_assembler("M=M-1");                // SP--
            
            output_assembler("@R13");                 // @13   
            output_assembler("A=M");                  // A=RAM[13]=LOCAL4
            output_assembler("M=D");                  // RAM[LOCAL4]=RAM[256]

        }else if(segment=="local"){

            output_assembler("@"+to_string(number));  // @4
            output_assembler("D=A");                  // D=4

            output_assembler("@LCL"); 
            output_assembler("D=D+M");                // D=4+RAM[1]=4+LOCAL0=LOCAL4

            output_assembler("@R13");                 //@13   
            output_assembler("M=D");                  // RAM[13]=LOCAL4

            output_assembler("@SP");                  // @0
            output_assembler("A=M-1");                // A=256 (SP POINTS TO)
            output_assembler("D=M");                  // D=RAM[256]
            output_assembler("@SP");                  // @0
            output_assembler("M=M-1");                // SP--
            
            output_assembler("@R13");                 // @13   
            output_assembler("A=M");                  // A=RAM[13]=LOCAL4
            output_assembler("M=D");                  // RAM[LOCAL4]=RAM[256]



        }else if(segment=="that"){
            output_assembler("@"+to_string(number));  // @4
            output_assembler("D=A");                  // D=4

            output_assembler("@THAT"); 
            output_assembler("D=D+M");                // D=4+RAM[1]=4+LOCAL0=LOCAL4

            output_assembler("@R13");                 //@13   
            output_assembler("M=D");                  // RAM[13]=LOCAL4

            output_assembler("@SP");                  // @0
            output_assembler("A=M-1");                // A=256 (SP POINTS TO)
            output_assembler("D=M");                  // D=RAM[256]
            output_assembler("@SP");                  // @0
            output_assembler("M=M-1");                // SP--
            
            output_assembler("@R13");                 // @13   
            output_assembler("A=M");                  // A=RAM[13]=LOCAL4
            output_assembler("M=D");                  // RAM[LOCAL4]=RAM[256]

        }else if(segment=="this"){
            output_assembler("@"+to_string(number));  // @4
            output_assembler("D=A");                  // D=4

            output_assembler("@THIS"); 
            output_assembler("D=D+M");                // D=4+RAM[1]=4+LOCAL0=LOCAL4

            output_assembler("@R13");                 //@13   
            output_assembler("M=D");                  // RAM[13]=LOCAL4

            output_assembler("@SP");                  // @0
            output_assembler("A=M-1");                // A=256 (SP POINTS TO)
            output_assembler("D=M");                  // D=RAM[256]
            output_assembler("@SP");                  // @0
            output_assembler("M=M-1");                // SP--
            
            output_assembler("@R13");                 // @13   
            output_assembler("A=M");                  // A=RAM[13]=LOCAL4
            output_assembler("M=D");                  // RAM[LOCAL4]=RAM[256]
        }
    }
    
    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// main program
int main(int argc,char **argv)
{
    // parse abstract syntax tree and pass to the translator
    translate_vm_class(ast_parse_xml()) ;

    // flush output and errors
    print_output() ;
    print_errors() ;
}
