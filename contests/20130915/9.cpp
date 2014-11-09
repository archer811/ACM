#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-8;
struct node
{
    double x;
    double y;
    double z;
}p[10], P, Q;
double s = 0, t = 0;

double pf(double a, double b)
{
    // printf("%lf\n",(a - b) * (a - b));
     return (a - b) * (a - b);

}

double dis(node a, node b)
{
     return sqrt(pf(a.x, b.x)*1.0 + pf(a.y, b.y)*1.0 + pf(a.z, b.z)*1.0);
}

void Cal()
{
     double t1 = pf(p[2].x, p[1].x)*1.0 + pf(p[2].y, p[1].y) + pf(p[2].z ,p[1].z);
     double t2 = (p[2].x - p[1].x) * (p[4].x - p[3].x) + (p[2].y - p[1].y) * (p[4].y - p[3].y)
                 + (p[2].z - p[1].z) * (p[4].z - p[3].z);
     double t3 = (p[1].x - p[2].x) * (p[1].x - p[3].x) + (p[1].y - p[2].y) * (p[1].y - p[3].y)
                 + (p[1].z - p[2].z) * (p[1].z - p[3].z);

     double t4 = pf(p[4].x, p[3].x) + pf(p[4].y, p[3].y) + pf(p[4].z ,p[3].z);
     double t5 = (p[1].x - p[3].x) * (p[4].x - p[3].x) + (p[1].y - p[3].y) * (p[4].y - p[3].y)
                 + (p[1].z - p[3].z) * (p[4].z - p[3].z);

  //   printf("t1=%lf t2=%lf t3 =%lf t4= %lf t5= %lf\n", t1, t2,t3,t4,t5);
   //  printf("t1=%lf t2=%lf t3 =%lf t4= %lf t5= %lf\n", t1*t5, t2*t3,t1*t4,t2*t2,t5*t2);

     t = (t1 * t5 + t2 * t3)*1.0 / (t1 * t4 - t2 * t2);
   //  printf("t = %lf\n", t);
     s = (t2 * t5 + t3 * t4)*1.0 / (t1 * t4 - t2 * t2);

}

int main()
{
    int t0;
    scanf("%d", &t0);
    for(int i = 1; i <= t0; i++)
    {
            memset(p, 0,sizeof(p[0]));
            for(int j = 1; j <= 4; j++)
            {
                     scanf("%lf %lf %lf", &p[j].x, &p[j].y, &p[j].z);
            }
            Cal();
            P.x = p[1].x + s * (p[2].x - p[1].x);
            P.y = p[1].y + s * (p[2].y - p[1].y);
            P.z = p[1].z + s * (p[2].z - p[1].z);

            Q.x = p[3].x + t * (p[4].x - p[3].x);
            Q.y = p[3].y + t * (p[4].y - p[3].y);
            Q.z = p[3].z + t * (p[4].z - p[3].z);

            double ans = dis(P, Q);
            printf("%.6f\n", ans+eps);
            printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",P.x, P.y, P.z, Q.x, Q.y, Q.z);


    }
    return 0;
}
