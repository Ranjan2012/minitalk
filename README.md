# Minitalk
he purpose of this project is to code a small data exchange program using UNIX signals

# What is a signal?
A signal is a notification to a process that an event has occurred. Signals are sometimes described as software interrupts.

One process can send a signal to another process. In this use, signals can be employed as a primitive form of interprocess communication (IPC).

Each signal is defined as a unique (small) integer, starting sequentially from 1. These integers are defined in <signal.h> with symbolic names of the form SIGxxxx. Since the actual numbers used for each signal vary across implementations, it is these symbolic names that are always used in programs.

A signal is said to be generated by some event. Once generated, a signal is later delivered to a process, which then takes some action in response to the signal. Between the time it is generated and the time it is delivered, a signal is said to be pending.

# What is a process?
A process is an instance of an executing program.

We can recast the definition of a process given at the start of this section as follows: a process is an abstract entity, defined by the kernel, to which system resources are allocated in order to execute a program.

From the kernel’s point of view, a process consists of user-space memory containing program code and variables used by that code, and a range of kernel data structures that maintain information about the state of the process. The information recorded in the kernel data structures includes various identifier numbers (IDs) associated with the process, virtual memory tables, the table of open file descriptors, information relating to signal delivery and handling, process resource usages and limits, the current working directory, and a host of other information.

# What is a program?
A program is a file containing a range of information that describes how to construct a process at run time. One program may be used to construct many processes, or, put conversely, many processes may be running the same program.

You must create a communication program in the form of a client and a server.

# What is a client-server application?
A client-server application is one that is broken into two component processes:

a client, which asks the server to carry out some service by sending it a request message; and
a server, which examines the client’s request, performs appropriate actions, and then sends a response message back to the client.
Sometimes, the client and server may engage in an extended dialogue of requests and responses.

Typically, the client application interacts with a user, while the server application provides access to some shared resource. Commonly, there are multiple instances of client processes communicating with one or a few instances of the server process.

The server must be started first. After its launch, it has to print its PID.

