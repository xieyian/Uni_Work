// a skeleton implementation of a tokeniser

#include "tokeniser.h"
#include <iostream>
#include <ctype.h>

// to shorten the code
using namespace std ;

bool floatornot = false;

////////////////////////////////////////////////////////////////////////

namespace Assignment_Tokeniser
{

    // is the token of the given kind or does it belong to the given grouping?
    bool token_is_in(Token token,TokenKind kind_or_grouping)
    {
        TokenKind kind = token_kind(token) ;

        // check identity first
        if ( kind == kind_or_grouping ) return true ;

        // this is best written as nested switch statements
        switch(kind_or_grouping)
        {
        default:
            return false ;
        }
    }

    // the current input character, initiliased to ' ' which we ignore
    // the eof marker can be confused with a legal character but not one accepted by our tokeniser
    static char ch = ' ' ;
    static char floatornot=false;
    // the current line number and column, initialised to line 1 column 0
    static int line_num = 1 ;
    static int column_num = 0 ;

    // the line number and column for the first character in the current token
    static int start_line = 0 ;
    static int start_column = 0 ;
    static bool checkfinish = false;
    // generate a context string for the given token
    // it shows the line before the token,
    // the line containing the token up to the end of the token, and
    // a line with a ^ marking the token's position
    // the lines are prefixed by line numbers, right justified in four spaces, followed by ': '
    // if a token extends over more than one line, only the part of the token on the first line is included
    string token_context(Token token)
    {
        return "" ;
    }

    // read next character if not at the end of input
    // and update the line and column numbers
    static void nextch()
    {
        if ( ch == EOF ) return ;

        if ( ch == '\n' )           // if last ch was newline ...
        {
            line_num++ ;            // increment line number
            column_num = 0 ;        // reset column number
        }

        if ( ch == '\t' )           // if last ch was tab ...
        {
            column_num+=3 ;        // increase column number by 4
        }

        ch = read_char() ;          // read the next character, probably from stdin but this could change during testing
        column_num++ ;              // increment the column number

                                    // additional code will be required here to handle preprocessing of '\t' and '\r'
                                    // you should also consider building a line by line copy of the input for use by token_context()
    }

    ////////////////////////////////////////////////////////////////////////
    // called when we find a digit - the start of an integer or float
    Token parse_integer(TokenKind kind,string spelling)
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        //switch();
        
        nextch();
        while(isdigit(ch)){
            spelling += ch ;
            nextch();
        }

            if(ch=='.'){
                floatornot=true;
                spelling += ch ;
                nextch();
                if(isdigit(ch)){
                while(isdigit(ch)){
                    spelling += ch ;
                    nextch();
                }
                    nextch();
                    if(ch=='0'){
                        spelling+="e+0";
                    }
                }else{
                    spelling+="0";
                }
                

                if(ch=='E'||ch=='e'){
                    spelling += ch ;
                    nextch();
                    while(isdigit(ch)){
                        spelling += ch ;
                        nextch();
                    }
                    //return new_token(kind_float, spelling, start_line,start_column);
                    if(ch=='+'||ch=='-'){
                        spelling += ch ;
                        nextch();
                        while(isdigit(ch)){
                            spelling += ch ;
                            nextch();
                        }
                        //return new_token(kind_float, spelling, start_line,start_column);
                    }
                }
            }
        if(floatornot==true && ch!='.'){
                    spelling +="e+0";
            }else if(ch=='E'||ch=='e'){
                spelling += ch ;
                nextch();
                while(isdigit(ch)){
                    spelling += ch ;
                    nextch();
                }
                //return new_token(kind_float, spelling, start_line,start_column);
                if(ch=='+'||ch=='-'){
                    spelling += ch ;
                    nextch();
                    while(isdigit(ch)){
                        spelling += ch ;
                        nextch();
                    }
                    //return new_token(kind_float, spelling, start_line,start_column);
                }
            }
        
    
    if(floatornot==false){
        floatornot=false;
         return new_token(kind, spelling, start_line,start_column) ;
    }else{
        floatornot=false;
        return new_token(tk_float, spelling, start_line,start_column) ;
    }
        
        
        // return an eoi token

    }
    
    // called when we find a 0 - a complete integer or the start of float
    Token parse_zero(TokenKind kind,string spelling)
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        nextch();
        while(isdigit(ch) && ch!='0'){
            spelling += ch ;
            nextch();
        }
        
        if(ch=='.'){
            floatornot=true;
            spelling += ch ;
            nextch();
            if(isdigit(ch)){
                while(isdigit(ch)){
                    spelling += ch ;
                    nextch();
                }
                nextch();
                if(ch=='0'){
                    spelling+="e+0";
                }
            }else{
                spelling+="0";
            }
            
            
            if(ch=='E'||ch=='e'){
                spelling += ch ;
                nextch();
                while(isdigit(ch)){
                    spelling += ch ;
                    nextch();
                }
                //return new_token(kind_float, spelling, start_line,start_column);
                if(ch=='+'||ch=='-'){
                    spelling += ch ;
                    nextch();
                    while(isdigit(ch)){
                        spelling += ch ;
                        nextch();
                    }
                    //return new_token(kind_float, spelling, start_line,start_column);
                }
            }
        }
        if(floatornot==true && ch!='.'){
            spelling +="e+0";
        }else if(ch=='E'||ch=='e'){
            spelling += ch ;
            nextch();
            while(isdigit(ch)){
                spelling += ch ;
                nextch();
            }
            //return new_token(kind_float, spelling, start_line,start_column);
            if(ch=='+'||ch=='-'){
                spelling += ch ;
                nextch();
                while(isdigit(ch)){
                    spelling += ch ;
                    nextch();
                }
                //return new_token(kind_float, spelling, start_line,start_column);
            }
        }
        
        
        if(floatornot==false){
            floatornot=false;
            return new_token(kind, spelling, start_line,start_column) ;
        }else{
            floatornot=false;
            return new_token(tk_float, spelling, start_line,start_column) ;
        }
    }

    
    // called when we find a-z A-Z _ $ . - start of a string
    Token parse_identifier(TokenKind kind,string spelling)
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        //switch();
        nextch();
        while ( isalnum(ch)  ||( ( ch=='_' || ch=='$'|| ch=='.'||ch=='\t' ) && spelling!="") ){
           
            spelling += ch ;
            nextch();
        }
        
        if(string_to_token_kind(spelling)==tk_do){
            nextch();
            return new_token(tk_do,spelling,start_line,start_column);
        }else if(string_to_token_kind(spelling)==tk_for){
            nextch();
            return new_token(tk_for,spelling,start_line,start_column);
        }else if(string_to_token_kind(spelling)==tk_pointer){
            nextch();
            return new_token(tk_pointer,spelling,start_line,start_column);
        }else if(string_to_token_kind(spelling)==tk_real){
            nextch();
            return new_token(tk_real,spelling,start_line,start_column);
        }else if(string_to_token_kind(spelling)==tk_this){
            nextch();
            return new_token(tk_this,spelling,start_line,start_column);
        }else{
        // return an eoi token
            return new_token(kind, spelling, start_line,start_column) ;
            
        }
    }
    
    /*
    // called when we find string . - start of a string
    Token parse_string(TokenKind kind,string spelling)
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        //switch();
        nextch();
        while ( ch=='"' || ch=='~'||ch=='#'||ch==' '||ch=='!'){
            if(ch!='"'){
                spelling += ch ;
            }
            nextch();
        }
        
        // return an eoi token
        return new_token(kind, spelling, start_line,start_column) ;
    }*/
    
    
    
    // called when we find some symbol - start of a symbol
    Token parse_symbol(TokenKind kind,string spelling)
     {
     // simulate end of input in case this is handling a bad token rather than a real end of input
     //switch();
    nextch();
    //if(ch=='/'){
      //  nextch();
         if(ch=='/'){
            nextch();
            spelling="";
            while(ch>=' ' && ch<='~'){
                if(ch=='\n'){
                    nextch();
                    return new_token(tk_eol_comment,spelling,start_line,start_column);
                }else{
                spelling+=ch;
                nextch();
                }
            }
            nextch();
            return new_token(tk_eol_comment,spelling,start_line,start_column);
   
       
    }else if(ch=='*' && spelling=="/"){
            nextch();
            spelling="";
            while(checkfinish==true||(ch=='\r' || ch=='\n' || (ch>=' ' && ch<='~'))){
                if(ch=='\r'){
                    nextch();
                }else{
                  spelling+=ch;
                  nextch();
                }
                if(ch=='*'){
                    spelling+=ch;
                    nextch();
                    if(ch=='/'){
                        checkfinish=true;
                        spelling.erase(spelling.size()-1,1); 
                        nextch();
                         return new_token(tk_adhoc_comment, spelling, start_line,start_column) ;
                    }
                }
            }
             return new_token(tk_adhoc_comment, spelling, start_line,start_column) ;
        }


     
     // return an eoi token
     return new_token(kind, spelling, start_line,start_column) ;
     }
    
    
    
   
    
    
    
    
    
    // called when we find end of input or we an error
    Token parse_eoi()
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        ch = EOF ;

        // return an eoi token
        return new_token(tk_eoi,"",start_line,start_column) ;
    }

    // return the next token object by reading more of the input
    Token next_token()
    {
        // you must read input using the nextch() function
        // the last character read is in the static variable ch
        // always read one character past the end of the token being returned

        string spelling = "" ;

        // this loop reads one character at a time until it reaches end of input
        while ( ch != EOF )
        {
            start_line = line_num ;                 // remember current position in case we find a token
            start_column = column_num;
            spelling = ch ;

            switch(ch)                              // ch is always the next char to read
            {
            case ' ':                               // ignore space and newline
            case '\t':
            case '\n':
            case '\r':
                nextch() ;                          // read one more character and try again
                break ;
                                                    // add additional case labels here for characters that can start tokens
                                                    // call a parse_*(kind,spelling) function to complete and return each kind of token
                                                    // this should follow the style used in the workshops
                                                    // but remember that the token grammar is different in this assignment


            
                    
            //case 'd': return parse_keyword(tk_do,spelling);
            //case 'f': return parse_keyword(tk_for,spelling);
            //case 'p': return parse_keyword(tk_pointer,spelling);
            //case 'r': return parse_keyword(tk_real,spelling);
            //case 't': return parse_keyword(tk_this,spelling);
            
            //case '"': return parse_string(tk_string, spelling);
            //case ' ': return parse_string(tk_string, spelling);
            //case '!': return parse_string(tk_string, spelling);
            //case '~': return parse_string(tk_string, spelling);
            //case '#': return parse_string(tk_string, spelling);
                    
            case '@': return parse_symbol(tk_at,spelling);
            case ';': return parse_symbol(tk_semi,spelling);
            case ':': return parse_symbol(tk_colon,spelling);
            case '!': return parse_symbol(tk_not,spelling);
            case ',': return parse_symbol(tk_comma,spelling);
            case '.': return parse_symbol(tk_stop,spelling);
           // case '==': return parse_symbol(tk_equal,spelling);
           // case '<==>': return parse_symbol(tk_spaceship,spelling);
            case '{': return parse_symbol(tk_lcb,spelling);
            case '}': return parse_symbol(tk_rcb,spelling);
            case '(': return parse_symbol(tk_lrb,spelling);
            case ')': return parse_symbol(tk_rrb,spelling);
            case '[': return parse_symbol(tk_lsb,spelling);
            case ']': return parse_symbol(tk_rsb,spelling);
            case '/': return parse_symbol(tk_div,spelling);
            //case '/': return parse_symbol(tk_div,spelling);
                    
                    
                    
                    
            //case '_': return parse_identifier(tk_identifier,spelling);
            //case '$': return parse_identifier(tk_identifier,spelling);
            //case '.': return parse_identifier(tk_identifier,spelling);
            case 'a'...'z': return parse_identifier(tk_identifier,spelling);
            case 'A'...'Z': return parse_identifier(tk_identifier,spelling);
                    
            case '0': return parse_zero(tk_integer,spelling);
            case '1'...'9': return parse_integer(tk_integer,spelling);
            default:
                return parse_eoi() ;                // the next character cannot start a token, this is an error, return an EOI token
            }
        }

        start_line = line_num ;                     // remember current position so EOI token is correct
        start_column = column_num ;

        return parse_eoi() ;                         // return an EOI token
    }
}
