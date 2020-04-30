import java.util.Random;

public class JavaImplementation {
	
	public static void main(String[] args) {
		
		Random rng = new Random();
		
		int[] int50 = new int[50];
		double[] dbl50 = new double[50];
		int[] int250 = new int[250];
		double[] dbl250 = new double[250];
		int[] int500 = new int[500];
		double[] dbl500 = new double[500];
		
		for(int i = 0; i < 50; i++) {
			int50[i] = rng.nextInt(1000);
			dbl50[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 250; i++) {
			int250[i] = rng.nextInt(1000);
			dbl250[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 500; i++) {
			int500[i] = rng.nextInt(1000);
			dbl500[i] = 1000 * rng.nextDouble();
		}
		
		int[] sortedInt100 = intSort(int50, dbl50);
		int[] sortedInt500 = intSort(int250, dbl250);
		int[] sortedInt1000 = intSort(int500, dbl500);
		
		double[] sortedDbl100 = dblSort(int50, dbl50);
		double[] sortedDbl500 = dblSort(int250, dbl250);
		double[] sortedDbl1000 = dblSort(int500, dbl500);
		
		for (int i = 0; i < sortedInt100.length; ++i) {
			System.out.print(sortedInt100[i] + " ");
			System.out.println();
		}
		
		
	
	}
	
	public static int[] intSort(int[] intArray, double[] dblArray) {
		int[] tempDblArray = new int[dblArray.length];
		for (int i = 0; i < dblArray.length; i++) {
			int temp = (int)dblArray[i];
			tempDblArray[i] = temp;
		}
		
		int[] sortedArray = new int[dblArray.length * 2];
		
		for(int i = 0; i < intArray.length; i++) {
			sortedArray[i] = intArray[i];
		}
		
		int k = 0;
		
		for(int i = dblArray.length; i < dblArray.length * 2 - 1; i++) {
			sortedArray[i] = tempDblArray[k++];
		}
		
		for(int i = 0; i < sortedArray.length - 1; i++) {
			for (int j = 0; j < sortedArray.length - i - 1; j++) {
				if (sortedArray[j] > sortedArray[j+1]) {
					int temp = sortedArray[j];
					sortedArray[j] = sortedArray[j+1];
					sortedArray[j+1] = temp;
				}
			}
		}
		
		return sortedArray;
	}
	
	public static double[] dblSort(int[] intArray, double[] dblArray) {
		double[] tempIntArray = new double[intArray.length];
		for (int i = 0; i < intArray.length; i++) {
			double temp = (double)intArray[i];
			tempIntArray[i] = temp;
		}
		
		double[] sortedArray = new double[intArray.length * 2];
		
		for(int i = 0; i < dblArray.length; i++) {
			sortedArray[i] = dblArray[i];
		}
		
		int k = 0;
		
		for(int i = intArray.length; i < intArray.length * 2 ; i++) {
			sortedArray[i] = tempIntArray[k++];
		}
		
		for(int i = 0; i < sortedArray.length - 1; i++) {
			for (int j = 0; j < sortedArray.length - i - 1; j++) {
				if (sortedArray[j] > sortedArray[j+1]) {
					double temp = sortedArray[j];
					sortedArray[j] = sortedArray[j+1];
					sortedArray[j+1] = temp;
				}
			}
		}
		
		return sortedArray;
	}

}
