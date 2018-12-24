int MPI_Send(void *buf,int count,MPI_Datatype datatype,int dest, int tag,MPI_Comm comm)

/*buf		starting address of the data to be sent
count	number of elements to be sent
datatype	MPI datatype of each element
dest		rank of destination process
tag		message marker (set by user)
comm		MPI communicator of processors  involved
MPI_SEND(data,500,MPI_REAL,6,33,MPI_COMM_WORLD,IERROR)
*/

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source,int tag, MPI_Comm comm, MPI_Status *status)
/*
Receiver can wildcard
To receive from any source
		MPI_ANY_SOURCE
To receive with any tag
		MPI_ANY_TAG
Actual source and tag are returned in the receiverâ€™s status parameter
Information from a wildcarded receive is returned from MPI_RECV in status handle
information           C
source				status.MPI_SOURCE
tag					status.MPI_TAG
count				MPI_Get_count


Message received may not fill receive buffer
count is number of elements actually received

int MPI_Get_count (MPI_Status *status,MPI_Datatype datatype, int *count)
*/
int MPI_Bcast (void *buffer,int count, MPI_Datatype datatype,int root, MPI_Comm comm)

int MPI_Reduce(void* sendbuf,void* recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
count is the number of “ops” done on consecutive elements of sendbuf (it is also size of recvbuf)
op is an associative operator that takes two operands of type datatype and returns a result of the same type

One-to-all communication: different data sent to each process in the communicator (in rank order)
int MPI_Scatter(void* sendbuf, int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, 	MPI_Datatype recvtype, int root, MPI_Comm comm)
sendcount is the number of elements sent to each process, not the “total” number sent
send arguments are significant only at the root process

All-to-one communication: different data collected by root process
Collection done in rank order
int MPI_Gather (void* sendbuf,int sendcount, MPI_Datatype sendtype, void* recvbuf, int recvcount, 	MPI_Datatype recvtype, int root, MPI_Comm comm)
Receive arguments only meaningful at the root process

int MPI_Allgather (void* sendbuf,int sendcount, MPI_Datatype sendtype, 	void* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
int MPI_Alltoall (void* sendbuf, int sendcount, MPI_Datatype sendtype, 	void* recvbuf, int recvcount, 	MPI_Datatype recvtype, MPI_Comm comm)


Non-Blocking Synchronous Send
int MPI_Issend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,MPI_Comm comm, MPI_Request *request)

Non-Blocking Receive
int MPI_Irecv(void *buf, int count, 	MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request)    no status

wait - routine does not return until completion finished
test - routine returns a TRUE or FALSE value depending on whether or not the communication has completed

int MPI_Wait(MPI_Request *request, MPI_Status *status)

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
