
// ****************************************************************
// BaseballStats.java
//
// Reads baseball data in from a comma delimited file. Each line
// of the file contains a name followed by a list of symbols
// indicating the result of each at bat: h for hit, o for out,
// w for walk, s for sacrifice. Statistics are computed and
// printed for each player.
// ****************************************************************
import java.util.Scanner;
import java.io.*;

public class BaseballStats {
	// -------------------------------------------------
	// Reads baseball stats from a file and counts
	// total hits, outs, walks, and sacrifice flies
	// for each player.
	// -------------------------------------------------
	public static void main(String[] args) throws IOException {

		Scanner fileScan;
		String fileName;
		Scanner scan = new Scanner(System.in);

		System.out.print("Enter the name of the input file: ");
		fileName = scan.nextLine();
		fileScan = new Scanner(new File(fileName));

		// Read and process each line of the file
		while (fileScan.hasNext()) {
			int flag = 1, o = 0, s = 0, h = 0, w = 0;
			String tmp = fileScan.nextLine();
			StringBuffer name = new StringBuffer("");
			for (int i = 0; i < tmp.length(); i++) {
				if (tmp.charAt(i) == ',') {
					if (flag == 1) {
						flag = 0;
						// System.out.println(name.toString());
					}
				} else {
					if (flag == 1)
						name.insert(i, tmp.charAt(i));
					else {
						if (tmp.charAt(i) == 's')
							s++;
						else if (tmp.charAt(i) == 'o')
							o++;
						else if (tmp.charAt(i) == 'w')
							w++;
						else
							h++;
					}
				}
			}
			System.out.println(name + "\th: " + h + " \to: " + o + " \tw: " + w + " \ts: " + s
					+ " \tBatting average: " + String.format("%.2f", h * 1.0 / (h + o)));
		}

		scan.close();
		fileScan.close();
	}
}