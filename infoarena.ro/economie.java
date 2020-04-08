import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
public class Main {

    public static int []numbers= new int[1005];
    public static boolean []obtainable= new boolean[50001];
    public static int []picked= new int[1005];
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileInputStream("economie.in"));
        int n=input.nextInt();
            int minn,maxx;
            numbers[1]=input.nextInt();
            minn=maxx=numbers[1];
            for(int i=2;i<=n;++i) {
                numbers[i]= input.nextInt();
                minn=Math.min(numbers[i],minn);
                maxx=Math.max(numbers[i],maxx);
            }
            input.close();
            Arrays.sort(numbers,1,n+1);

            int ans=0;
            for(int i=1;i<=n;++i) {
                if(!obtainable[numbers[i]]) {
                    picked[++ans]=numbers[i];
                    obtainable[numbers[i]]=true;
                    for(int j=minn;j<=maxx-numbers[i];++j) {
                        if(obtainable[j]) {
                            obtainable[numbers[i]+j]=true;
                        }
                    }
                }
            }
            PrintStream output = new PrintStream("economie.in");
            output.println(ans);
            for(int i=1;i<=ans;++i) {
                output.printf("%d ",picked[i]);
            }
            output.close();
    }
}