import java.util.Random;

public class JavaImplementation2 {
	
	public static void main(String[] args) {
		
		Random rng = new Random();
		

		double[] dblArrayA100 = new double[100];
		
		double[] dblArrayB100 = new double[100];
		
		double[] dblArrayC100 = new double[100];
		
		
		
		
		
		for (int i = 0; i < 100; i++) {
			
			dblArrayA100[i] = 1000 * rng.nextDouble();
			dblArrayB100[i] = 1000 * rng.nextDouble();
			dblArrayC100[i] = 1000 * rng.nextDouble();
			
		}
		
		int[] intSumArray100 = intSum(dblArrayA100, dblArrayB100, dblArrayC100);
		
		double[] dblSumArray100 = dblSum(dblArrayA100, dblArrayB100, dblArrayC100);
		
		double[] difference = new double[100];
		
		for (int i = 0; i < 100; i++) {
			double temp = intSumArray100[i] - dblSumArray100[i];
			difference[i] = Math.abs(temp);
		}
		
		for (int i = 0; i < 100; i++) {
			System.out.println("Original Value: " + dblSumArray100[i]);
			System.out.println("Typecasted Value: " + intSumArray100[i]);
			System.out.println("Difference: " + difference[i]);
			System.out.println(" ");
		}
		
	}
	
	public static int[] intSum( double[] dblArr1, double[] dblArr2, double[] dblArr3) {
		int[] sumArr = new int[dblArr1.length];
		int[] b = new int[dblArr1.length];
		int[] c = new int[dblArr2.length];
		int[] a = new int[dblArr3.length];
		
		for (int i = 0; i < b.length; i++) {
			
			a[i] = (int)dblArr1[i];
			b[i] = (int)dblArr2[i];
			c[i] = (int)dblArr3[i];
		}
		
		
		for(int i = 0; i < sumArr.length; i++) {
			sumArr[i] = -(a[i]*a[i])+((b[i]*b[i])+(c[i]*c[i])-4*a[i]*c[i])/(2*a[i]*c[i]+c[i]*a[i]*b[i]);
		}
		
		return sumArr;
	}
	
	public static double[] dblSum(double[] a, double[] b, double[] c) {
		double[] sumArr = new double[b.length];
		
		
		
		for(int i = 0; i < sumArr.length; i++) {
			sumArr[i] = -(a[i]*a[i])+((b[i]*b[i])+(c[i]*c[i])-4*a[i]*c[i])/(2*a[i]*c[i]+c[i]*a[i]*b[i]);
		}
		
		return sumArr;
	}

}
