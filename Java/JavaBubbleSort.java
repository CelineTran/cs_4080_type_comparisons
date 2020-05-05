import java.util.Random;

public class JavaImplementation {
	
	public static void main(String[] args) {
		
		Random rng = new Random();
		
		
		double[] dbl250 = new double[250];
		
		double[] dbl500 = new double[500];
		
		double[] dbl750 = new double[750];
		
		double[] dbl1000 = new double[1000];
		
		int[] int125 = new int[125];
		double[] dbl125 = new double[125];
		
		int[] int250 = new int[250];
		double[] dbl250B = new double[250];
		
		int[] int375 = new int[375];
		double[] dbl375 = new double[375];
		
		int[] int500 = new int[500];
		double[] dbl500B = new double[500];
		
		for(int i = 0; i < 125; i++) {
			int125[i] = rng.nextInt(1000);
			dbl125[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 250; i++) {
			int250[i] = rng.nextInt(1000);
			dbl250B[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 375; i++) {
			int375[i] = rng.nextInt(1000);
			dbl375[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 375; i++) {
			int500[i] = rng.nextInt(1000);
			dbl500B[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 250; i++) {
			
			dbl250[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 500; i++) {
			
			dbl500[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 750; i++) {
			
			dbl750[i] = 1000 * rng.nextDouble();
		}
		
		for(int i = 0; i < 1000; i++) {
			dbl1000[i] = 1000 * rng.nextDouble();
		}
		
		
		double time250A=0, time250B= 0, time500A=0, time500B=0, time750A=0, time750B=0, time1000A=0, time1000B=0;
		double mix1 = 0, mix2 = 0, mix3 = 0, mix4 = 0;
		
		for (int i = 0; i < 10; i++) {
			long startTime1 = System.nanoTime();
			intSort(dbl250);
			long elapsedTime1 = System.nanoTime() - startTime1;
			time250A = time250A + elapsedTime1;
			
			long startTime2 = System.nanoTime();
			dblSort(dbl250);
			long elapsedTime2 = System.nanoTime() - startTime2;
			time250B = time250B + elapsedTime2;
			
			long startTime3 = System.nanoTime();
			intSort(dbl500);
			long elapsedTime3 = System.nanoTime() - startTime3;
			time500A = time500A + elapsedTime3;
			
			long startTime4 = System.nanoTime();
			dblSort(dbl500);
			long elapsedTime4 = System.nanoTime() - startTime4;
			time500B = time500B + elapsedTime4;
			
			long startTime5 = System.nanoTime();
			intSort(dbl750);
			long elapsedTime5 = System.nanoTime() - startTime5;
			time750A = time750A + elapsedTime5;
			
			long startTime6 = System.nanoTime();
			dblSort(dbl750);
			long elapsedTime6 = System.nanoTime() - startTime6;
			time750B = time750B + elapsedTime6;
			
			long startTime7 = System.nanoTime();
			intSort(dbl1000);
			long elapsedTime7 = System.nanoTime() - startTime7;
			time1000A = time1000A + elapsedTime7;
			
			long startTime8 = System.nanoTime();
			dblSort(dbl1000);
			long elapsedTime8 = System.nanoTime() - startTime8;
			time1000B = time1000B + elapsedTime8;
			
			long startTime9 = System.nanoTime();
			mixedSort(int125, dbl125);
			long elapsedTime9 = System.nanoTime() - startTime9;
			mix1 = mix1 + elapsedTime9;

			long startTime10 = System.nanoTime();
			mixedSort(int250, dbl250B);
			long elapsedTime10 = System.nanoTime() - startTime10;
			mix2 = mix2 + elapsedTime10;
			
			long startTime11 = System.nanoTime();
			mixedSort(int375, dbl375);
			long elapsedTime11 = System.nanoTime() - startTime11;
			mix3 = mix3 + elapsedTime11;
			
			long startTime12 = System.nanoTime();
			mixedSort(int500, dbl500B);
			long elapsedTime12 = System.nanoTime() - startTime12;
			mix4 = mix4 + elapsedTime12;
			
			
		}
		
		time250A = time250A / 10;
		time250B = time250B / 10;
		time500A = time500A / 10;
		time500B = time500B / 10;
		time750A = time750A / 10;
		time750B = time750B / 10;
		time1000A = time1000A / 10;
		time1000B = time1000B / 10;
		mix1 = mix1 / 10;
		mix2 = mix2 / 10;
		mix3 = mix3 / 10;
		mix4 = mix4 / 10;
		
		double[] sum = mixedSort(int125, dbl125);
		
		for (int i = 0; i < 125; i++ ) {
			System.out.println(sum[i]);
			System.out.println(" ");
		}
		
		System.out.println("With Type Coercion --");
		System.out.println("Average time of 10 trials of size 250 is " + time250A/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 500 is " + time500A/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 750 is " + time750A/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 1000 is " + time1000A/1000000000 + " seconds");
		System.out.println("Without Type Coercion (Original List) --");
		System.out.println("Average time of 10 trials of size 250 is " + time250B/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 500 is " + time500B/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 750 is " + time750B/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 1000 is " + time1000B/1000000000 + " seconds");
		System.out.println("Mixed-Type -- ");
		System.out.println("Average time of 10 trials of size 250 is " + mix1/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 500 is " + mix2/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 750 is " + mix3/1000000000 + " seconds");
		System.out.println("Average time of 10 trials of size 1000 is " + mix4/1000000000 + " seconds");
		
	
	}
	
	public static int[] intSort(double[] dblArray) {
		int[] intArray = new int[dblArray.length];
		for (int i = 0; i < dblArray.length; i++) {
			int temp = (int)dblArray[i];
			intArray[i] = temp;
		}
		
		
		for(int i = 0; i < intArray.length - 1; i++) {
			for (int j = 0; j < intArray.length - i - 1; j++) {
				if (intArray[j] > intArray[j+1]) {
					int temp = intArray[j];
					intArray[j] = intArray[j+1];
					intArray[j+1] = temp;
				}
			}
		}
		
		return intArray;
	}
	
	public static double[] dblSort(double[] dblArray) {
		
		
		for(int i = 0; i < dblArray.length - 1; i++) {
			for (int j = 0; j < dblArray.length - i - 1; j++) {
				if (dblArray[j] > dblArray[j+1]) {
					double temp = dblArray[j];
					dblArray[j] = dblArray[j+1];
					dblArray[j+1] = temp;
				}
			}
		}
		
		return dblArray;
	}
	
	public static double[] mixedSort(int[] intArray, double[] dblArray) {
		double[] tempArray = new double[dblArray.length*2];
		
		for(int i = 0; i < dblArray.length; i++) {
			tempArray[i] = dblArray[i];
		}
		
		int k = 0;
		
		for(int i = intArray.length; i < intArray.length * 2; i++) {
			tempArray[i] = intArray[k++];
		}
		
		for(int i = 0; i < tempArray.length - 1; i++) {
			for (int j = 0; j < tempArray.length - i - 1; j++) {
				if (tempArray[j] > tempArray[j+1]) {
					double temp = tempArray[j];
					tempArray[j] = tempArray[j+1];
					tempArray[j+1] = temp;
				}
			}
		}
		
		return tempArray;
		                          
	}

}
