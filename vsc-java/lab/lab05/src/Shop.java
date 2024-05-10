// ***************************************************************
// Shop.java
//
// Uses the Item class to create items and add them to a shopping
// cart stored in an ArrayList.
// ***************************************************************
import java.util.ArrayList;
import java.util.Scanner;
public class Shop
{
	public static void main (String[] args)
	{
		Item item;
		String itemName;
		double itemPrice, totalPrice = 0;
		int quantity;
		ArrayList<Item> cart = new ArrayList<Item> ();
		
		Scanner scan = new Scanner(System.in);
		String keepShopping = new String("y");
		
		// *** input all item's name, price, quantity
		while (keepShopping.equals("y"))
		{
			System.out.print ("Enter the name of the item: ");
			itemName = scan.nextLine();
			System.out.print ("Enter the unit price: ");
			itemPrice = scan.nextDouble();
			System.out.print ("Enter the quantity: ");
			quantity = scan.nextInt();
			
			// *** create a new item and add it to the cart 
			item = new Item(itemName, itemPrice, quantity);
			cart.add(item);
			System.out.println(cart);
			
			// *** print the contents of the cart object using println
			System.out.print ("Continue shopping (y/n)? ");
			keepShopping = scan.nextLine();
			keepShopping = scan.nextLine();
			
			totalPrice += quantity * itemPrice;
		}
		// *** print the total price
		System.out.println("Total price: " + totalPrice);

		scan.close();
	}
}