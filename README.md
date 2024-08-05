<a href="#">
    <img src="https://github.com/LouAntonio/42-resources/blob/main/resourses/minitalk.png" style="width: 100%"/>
</a>

# MINITALK
Minitalk aims to create a server and a client program in order to comunicate with each other.

<img src="https://github.com/LouAntonio/42-resources/blob/main/resourses/avaluations/minitalk.png"/>

It is not allowd to send the entire message or char by char, so, the only way is using unix signails and bitwise operators.

At the start, the server must print his own PID (Process ID), and the client recieves two parameters - the target PID and the message to be sent. If it is all right with the input values, the client starts a loo to iterate every single char from the message, sending them bit by bit using bitwise operations, singnal sending functions and unix predefined signals.

So, the server recieves the bits, and 'rebuild' the message writing her in the standard output.

The client and the server must be able to send and recieve any kind of character, respectively, and the server must be able to recieve several messages from different clients without need to restart.

> The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.

