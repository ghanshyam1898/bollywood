#include<ctype.h>
#include<cvowel.c>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<process.h>


void help()
{
clrscr();
textcolor(5);
cprintf("In this bollywood game, player 1 needs to enter a movie name when it asks for it and press \"enter\" key. Then all the letters of movie name are hidden (except vowels) then within 12 attempts, player 2 have to guess the movie name.\r\nNOTE : YOU CAN PRESS \"#\" WHILE IT ASKS TO GUESS AN ALPHABET TO ENTER THE WHOLE\r\n NAME DIRECTLY.\r\nGOOD LUCK!!");
getch();
exit(1);
}

void main()
{
char movie[50],direct[50],display[50],input,typed[26];
int i,p=0,k,attempt=12;
clrscr();
highvideo();
textcolor(3);
cprintf("                            WELCOME TO BOLLYWOOD");
cprintf("\r\n                                          the game of challengers");
textcolor(6);
cprintf("\r\nEnter the movie name (or press ! for help) : ");
gets(movie);
if(strcmp(movie,"!")==0)
help();
clrscr();
for(i=0;i<strlen(movie);i++)
{
	display[i]=movie[i];
	if(isalnum(movie[i]))
	{
		display[i]='*';
	}
	if(isvowel(movie[i]))
	{
		display[i]=movie[i];
	}
}
textcolor(3);
for(k=2500;k>2450;k--)
{
sound(k);
delay(5);
}
nosound();
cprintf("\r\n\r\nYour progress is  : %s",display);
again :
if(attempt<=0)
{
	textcolor(4);
	cprintf("\r\n\r\nYou have lost the game.\r\nThe movie was : %s",movie);
	sound(2000);
	sleep(2);
	nosound();
	getch();
	exit(1);
}
textcolor(6);
cprintf("\r\n\r\nAttempts left = %d",attempt);
cprintf("\r\nYou have already typed : %s",typed);
cprintf("\r\n\r\nEnter your choice : ");
input=getch();
typed[p]=input;
typed[p+1]=' ';
p+=2;
if(input=='#')
goto direct_input;
if(0)
{
direct_input :
cprintf("\r\n\r\n\r\nEnter the full movie name : ");
gets(direct);
if(strcmp(direct,movie)==0)
goto gotit;
else
{
cprintf("\r\n\r\n\r\nYou have guessed the wrong movie.Your attempts have been reduced by 3\r\n as a punishment.");
attempt-=3;
sound(1000);
sleep(1);
nosound();
cprintf("\r\nYour progress is : %s",display);
goto again;
}
}
attempt-=1;
for(i=0;i<strlen(movie);i++)
{
	if(strcmpi(movie[i],input)==0)
	{
		display[i]=input;
		sound(1000);
		delay(70);
		nosound();
	}
}
clrscr();
textcolor(6);
cprintf("\r\n\r\nYour progress is : %s",display);
if(strcmp(movie,display)==0)
{
	gotit :
	textcolor(2);
	cprintf("\r\n\r\n\r\nCONGRTATULATION !! YOU WON !");
	for(k=1000;k<2000;k++)
	{
	if(k%2==0)
	{
	sound((k+50));
	delay(3);
	}
	else
	{
	sound((k-100));
	delay(3);
	}
	}
	nosound();
	getch();
	exit(1);
}
goto again;
}
