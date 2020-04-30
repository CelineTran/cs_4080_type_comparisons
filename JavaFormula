import java.util.Random;

public class JavaImplementation2 {
	
	public static void main(String[] args) {
		
		Random rng = new Random();
		
		int[] intArray10 = new int[10];
		int[] intArray50 = new int[50];
		int[] intArray100 = new int[100];
		
		double[] dblArrayA10 = new double[10];
		double[] dblArrayA50 = new double[50];
		double[] dblArrayA100 = new double[100];
		
		double[] dblArrayB10 = new double[10];
		double[] dblArrayB50 = new double[50];
		double[] dblArrayB100 = new double[100];
		
		for (int i = 0; i < 10; i++) {
			intArray10[i] = rng.nextInt(1000);
			dblArrayA10[i] = 1000 * rng.nextDouble();
			dblArrayB10[i] = 1000 * rng.nextDouble();
			
		}
		
		for (int i = 0; i < 50; i++) {
			intArray50[i] = rng.nextInt(1000);
			dblArrayA50[i] = 1000 * rng.nextDouble();
			dblArrayB50[i] = 1000 * rng.nextDouble();
			
		}
		
		for (int i = 0; i < 100; i++) {
			intArray100[i] = rng.nextInt(1000);
			dblArrayA100[i] = 1000 * rng.nextDouble();
			dblArrayB100[i] = 1000 * rng.nextDouble();
			
		}
		
		int[] intSumArray10 = intSum(intArray10, dblArrayA10, dblArrayB10);
		int[] intSumArray50 = intSum(intArray50, dblArrayA50, dblArrayB50);
		int[] intSumArray100 = intSum(intArray100, dblArrayA100, dblArrayB100);
		
		double[] dblSumArray10 = dblSum(intArray10, dblArrayA10, dblArrayB10);
		double[] dblSumArray50 = dblSum(intArray50, dblArrayA50, dblArrayB50);
		double[] dblSumArray100 = dblSum(intArray100, dblArrayA100, dblArrayB100);
		
		
		
	}
	
	public static int[] intSum(int[] a, double[] dblArr1, double[] dblArr2) {
		int[] sumArr = new int[a.length];
		int[] b = new int[dblArr1.length];
		int[] c = new int[dblArr2.length];
		
		for (int i = 0; i < b.length; i++) {
			b[i] = (int)dblArr1[i];
			c[i] = (int)dblArr2[i];
		}
		
		
		for(int i = 0; i < sumArr.length; i++) {
			sumArr[i] = -(a[i]*a[i])+((b[i]*b[i])+(c[i]*c[i])-4*a[i]*c[i])/(2*a[i]*c[i]+c[i]*a[i]*b[i]);
		}
		
		return sumArr;
	}
	
	public static double[] dblSum(int[] intArr, double[] b, double[] c) {
		double[] sumArr = new double[b.length];
		double[] a = new double[intArr.length];
		
		
		for (int i = 0; i < b.length; i++) {
			a[i] = (double)intArr[i];
		}
		
		
		for(int i = 0; i < sumArr.length; i++) {
			sumArr[i] = -(a[i]*a[i])+((b[i]*b[i])+(c[i]*c[i])-4*a[i]*c[i])/(2*a[i]*c[i]+c[i]*a[i]*b[i]);
		}
		
		return sumArr;
	}

}
