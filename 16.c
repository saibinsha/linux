#include<stdio.h>
struct Process { int id, bt, rt; };
void rr(struct Process p[], int n, int q) {
    int t = 0, done;
    do {
        done = 1;
        for(int i = 0; i < n; i++) {
            if(p[i].rt > 0) {
                done = 0;
                if(p[i].rt > q) { t += q; p[i].rt -= q; }
                else { t += p[i].rt; p[i].rt = 0; printf("Process %d finshed at %d\n", p[i].id, t); }
            }
        }
    } while(!done);
}
int main() {
    int n, q; printf("enter the no of Processes: "); scanf("%d", &n);
    struct Process p[n]; for(int i = 0; i < n; i++) {
        p[i].id = i+1; printf("enter burst time for  P%d: ", i+1); scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    } printf("enter time Quantum: "); scanf("%d", &q); rr(p, n, q);
}
