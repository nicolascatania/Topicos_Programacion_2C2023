#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED


#define ROUND(x) ((x) >= 0 ? (int)((x) + 0.5) : (int)((x) - 0.5))
#define VAL_ABS(x) (x<0)?(-1*x):x
#define PARTE_ENTERA(x) ((int)x)
#define PARTE_DECIMAL(numero) ((numero) - (int)(numero))
#define ES_MAYUS(x) (x>='A')&&(x<='Z')
#define ES_MINUS(x) (x>='a')&&(x<='z')
#define A_MAYUS(x) ((x>='a' && x<='z')?(x-('a'-'A')):x)
#define A_MINUS(x) (((x) >= 'A' && (x) <= 'Z') ? ((x) - ('A' - 'a')) : (x))
#define ES_LETRA(x) (((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z'))
#define ES_PAR(numero) ((numero) % 2 == 0)
#define ES_DIGITO(caracter) ((caracter) >= '0' && (caracter) <= '9')
#define ES_BLANCO(caracter) ((caracter) == ' ' || (caracter) == '\t' || (caracter) == '\n' || (caracter) == '\r')

#endif // MACROS_H_INCLUDED
