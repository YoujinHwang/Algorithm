import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int[] arr=new int[n+1];
        StringBuilder sb=new StringBuilder();

        st=new StringTokenizer(br.readLine());
        arr[0]=0;
        for(int i=1;i<=n;i++) {
            arr[i]=arr[i-1]+Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<m;i++) {
            st=new StringTokenizer(br.readLine());
            int begin=Integer.parseInt(st.nextToken());
            int end=Integer.parseInt(st.nextToken());
            sb.append(arr[end]-arr[begin-1]).append("\n");
        }
        System.out.println(sb);

    }
}
