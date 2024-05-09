import java.util.Scanner;

enum Rank {
    ace, two, three, four, five, six,
    seven, eight, nine, ten, jack, queen, king
};

public class Cards {
    private Rank highCard = Rank.ace;
    private Rank faceCard;
    private Rank card1;
    private Rank card2;
    private int card1Val;
    private int card2Val;

    Cards(String faceCard) {
        if (faceCard.equals("jack"))
            this.faceCard = Rank.jack;
        if (faceCard.equals("queen"))
            this.faceCard = Rank.queen;
        if (faceCard.equals("king"))
            this.faceCard = Rank.king;
        System.out.println("A blackjack hand: " + highCard + " and " + this.faceCard);
    }

    public void setCard(int val1, int val2) {
        switch (val1) {
            case 2:
                card1 = Rank.two;
                break;

            case 3:
                card1 = Rank.three;
                break;

            case 4:
                card1 = Rank.four;
                break;

            case 5:
                card1 = Rank.five;
                break;

            case 6:
                card1 = Rank.six;
                break;

            case 7:
                card1 = Rank.seven;
                break;

            case 8:
                card1 = Rank.eight;
                break;

            case 9:
                card1 = Rank.nine;
                break;

            case 10:
                card1 = Rank.ten;
                break;

            default:
                break;
        }

        switch (val2) {
            case 2:
                card2 = Rank.two;
                break;

            case 3:
                card2 = Rank.three;
                break;

            case 4:
                card2 = Rank.four;
                break;

            case 5:
                card2 = Rank.five;
                break;

            case 6:
                card2 = Rank.six;
                break;

            case 7:
                card2 = Rank.seven;
                break;

            case 8:
                card2 = Rank.eight;
                break;

            case 9:
                card2 = Rank.nine;
                break;

            case 10:
                card2 = Rank.ten;
                break;

            default:
                break;
        }
        this.card1Val = val1;
        this.card2Val = val2;
    }

    public String toString() {
        return "A two card hand: " + card1 + " and " + card2 + '\n' +
                "Hand value: " + (card1Val + card2Val);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Choose faceCard:(jack,queen,king)");
        String faceCard = scan.next();

        Cards lab = new Cards(faceCard);
        System.out.print("Input two card's val(Integer):");
        int card1Val = scan.nextInt(), card2Val = scan.nextInt();
        lab.setCard(card1Val, card2Val);

        System.out.println(lab);
        scan.close();
    }
}
