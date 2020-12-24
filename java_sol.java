import java.io.*;
import java.util.*;

public class Main {
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int t=in.nextInt();
//		int t=1;
		for(int i=1; i<=t; ++i)
			new Solver();
		out.close();
	}
	
	static class Solver {
		Solver() {
			long[] a = new long[3];
			long[] b = new long[2];
			for(int i=0; i<3; ++i)
				a[i]=in.nextLong();
			for(int i=0; i<2; ++i)
				b[i]=in.nextLong();
			Arrays.sort(a);
			Arrays.sort(b);
			boolean ok=false;
			do {
				do {
					long one=b[0]-a[0];
					long two=b[1]-a[1];
					if(one>=0&&two>=0&&one+two==a[2])
						ok=true;
				} while(next_permutation(b));
			} while(next_permutation(a));
			out.println(ok?"YES":"NO");
		}
		boolean next_permutation(long[] a) {
			boolean ok=false;
			int i;
			for(i=(int)a.length-2; i>=0; --i)
				if(a[i]<a[i+1]) {
					ok=true;
					break;
				}
			if(!ok)
				return false;
			int j;
			for(j=i+1; j<(int)a.length; ++j)
				if(a[j]<=a[i])
					break;
			--j;
			swap(a, i, j);
			reverse(a, i+1, a.length);
			return true;
		}
		void swap(long[] a, int i, int j) {
			long tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
		void reverse(long[] a, int s, int e) {
			for(int i=s, j=e-1; i<j; ++i, --j)
				swap(a, i, j);
		}
	}
	
	static class Reader {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(in.readLine());
				} catch(Exception e) {}
			}	
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	
}
