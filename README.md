# Word-Editor
Function/Module:

•	void intro(); 
This is a function that starts after int main(), Here the function asks for the pwd. After correct password, i.e(tanmay22 or kartik96) is entered, the loading screen open.
For checking the password. String compare function is used to compare if the input string is equal to the string stored in the program code.  

•	void gotoxy(int x,int y);
This is function used to use gotoxy. Gotoxy helps us to go to any coordinate, x and y axis of the whole console output. This has helped us a lot to improve the UI of our program.

•	void input_data(int);
This is for taking input from the user.
Each line is take as an array and stored into a link list through createnewline function, explained below.

•	void lin();
This is for making lines. Used in the program occasionally to improve user program interface. 
To output the line, simple we have out putted 80 underline character, i.e ‘_’. 80, because that are in the number of characters possible on console output screen.

•	line* createnewline(char[]);
This function is called from input_data() function. The character array is stored in a linklist. This link list has two pointer which are prev and next. Both are defined NULL here.  

•	void add(line*);
Here we add the line at the end of our existing link list. We point the prev of the line* to the structure pointer which rear stored. The next of rear pointer is pointed to this new pointer and rear is made to point the this new pointer. 

•	void del(int);

•	void copy_paste(int,int,int);
Here we initial a new structure pointer of line called curr_c. It is made to point the the linklist which has to be copied by incrementing is step by step according to the line no. entered by the user.
Simillarly, another pointer curr_l is made to incremented step by step to point to the pointer after which the value of pointer pointed by curr_c has to be pasted according to the paste line number entered by user.
Then there is a check statement which check if the user entered the last line. If true,  a pointer  paste_line is initialed with the value of the arr which has to be pasted. Paste_line->next is made to point curr_l->next, paste_line->prev then points curr_l , curr_l->next point paste_line and finally rear is made equal to paste_line;
If the user has not entered the last line then also a pointer paste_line is initialed with the value of the arr which has to be pasted. Temp is pointed to curr_l->next,paste_line->next is pointed by curr_l->next, paste_line->prev is pointed by curr_l, curr_l->next is pointed by paste_line and finally temp->prev is pointed by paste_line.

•	void cut_paste(int,int,int); 

•	void display();
structure line pointer, curr is made to point start. Then a while loop is ran which prints the value of array stored in curr as well as increments the value of curr to next pointer. It keeps on running until the end of link list is reached that is checked if the curr->next points to NULL or not.

•	void rev();
structure line pointer, curr is made to point rear. Then a while loop is ran which prints the value of array stored in curr as well as decrements the value of curr to previous pointer. It keeps on running until the starting of link list is reached that is checked if the curr->prev points to NULL or not.

•	void exit();
This is function that displays our name and registration no. using cout operation with lines and gotoxy function to improve the UI.

