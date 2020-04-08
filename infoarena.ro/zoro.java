import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static class Pair {
        int x=0,y=0;
        public void create(int x, int y) {
            this.x=x;
            this.y=y;
        }
    }
    public static void main(String[] args) throws IOException {
	    Scanner input= new Scanner(new FileInputStream("zoro.in"));
	    PrintStream output= new PrintStream("zoro.out");
        int n= input.nextInt();
        int m=input.nextInt();
        int start=0,finish=0;
        Pair[] positions= new Pair[n*m+1];
        int []line= new int[n+1];
        int []column= new int[m+1];
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                int num=input.nextInt();
                positions[num]=new Pair();
                positions[num].create(i,j);
                /*Pair aux = new Pair();
                aux.x=i;
                aux.y=j;
                positions[num]=aux;*/
                if (i == 1 && j == 1)
                    start = num;
                if (i == n && j == m)
                    finish = num;
            }
        }
        line[1]=column[1]=0;
        int ans=0;
        for(int i=start;i>=finish;--i) {
            ans=Math.max(line[positions[i].x],column[positions[i].y]) +1;
            line[positions[i].x]=column[positions[i].y]=ans;
        }
        output.print(ans);
        output.close();
        input.close();
    }
}
