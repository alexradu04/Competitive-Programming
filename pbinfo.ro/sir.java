import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class sir {

    enum Sign {
        Plus,
        Minus
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(new FileInputStream("sir.in"));
        PrintStream output= new PrintStream("sir.out");
        int n=sc.nextInt();
        int[] v = new int[100005];
        int[] swapFromIndex = new int[100005];
        Sign[] sign = new Sign[100005];
        for(int i=1;i<=n;++i) {
            v[i]=sc.nextInt();
        }
        int partialSum=v[n];
        sign[n]=Sign.Plus;
        for(int i=n-1;i>=1;--i) {
            if(partialSum>=v[i]) {
                sign[i]=Sign.Minus;
                partialSum-=v[i];
            } else {
                sign[i]=Sign.Plus;
                swapFromIndex[i+1]=1;
                partialSum=v[i]-partialSum;
            }
        }
        for(int i=1;i<=n;++i) {
            swapFromIndex[i]+=swapFromIndex[i-1];
        }
        for(int i=1;i<=n;++i) {
            if(swapFromIndex[i]%2==1) {
                sign[i]=(sign[i]== Sign.Plus)? Sign.Minus : Sign.Plus;
            }
        }
        StringBuilder ans= new StringBuilder();
        for(int i=1;i<=n;++i) {
            ans.append((sign[i] == Sign.Plus) ? '+' : '-');
        }
        output.println(ans);
        sc.close();
        output.close();

    }
}