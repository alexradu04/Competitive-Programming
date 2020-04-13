import java.util.Scanner;
import java.io.*;
public class Main {

    public static void main(String[] args) throws Exception {
	    long tc;
        //Scanner sc= new Scanner(System.in);
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        //tc=sc.nextLong();
        tc=Integer.parseInt(bu.readLine());
        StringBuilder sb=new StringBuilder();
        long[] a = new long[300005];
        long[] b = new long[300005];
        for(long idx=1;idx<=tc;++idx) {
            long ans=0;
            int minn=1;
            int n=Integer.parseInt(bu.readLine());
            //int n=sc.nextInt();
            for(int i=1;i<=n;++i) {
                String s[]=bu.readLine().split(" ");
                a[i]=Long.parseLong(s[0]);
                b[i]=Long.parseLong(s[1]);
            }
            a[n+1]=a[1];
            b[n+1]=b[1];
            for(int i=1;i<=n;++i) {
                b[i]=Math.min(b[i],a[i+1]);
            }
            a[n+1]=a[1];
            b[n+1]=b[1];
            for(int i=1;i<=n;++i) {
                if(b[i]<b[minn]) {
                    minn=i;
                }
            }
            for(int i=2;i<=n+1;++i) {
                if(i!=minn+1) {
                    ans+=a[i]-b[i-1];
                } else {
                    ans+=a[i];
                }
            }
            sb.append(ans).append("\n");
        }
        System.out.print(sb);
    }
}
