public class Item {
	private String name;
	private double price;
	private int quantity;
	
	Item(String name, double price, int quantity){
		this.name = name;
		this.price = price;
		this.quantity = quantity;
	}
	
	public double getPrice() {
		return price;
	}
	
	public int getQuantity() {
		return quantity;
	}
	
	public String toString() {
		return "\tItem_name:" + name + " Item_price: " + getPrice() + " Item_quantity: " + getQuantity() + '\n';
	}
}
