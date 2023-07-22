package group4618.pozdnyakov.lesson2.exercise1;

public class Human extends Actor {

    public Human(String name) {
        super(name);
    }

    public String getName() {
        return name;
    }    

    @Override
    public boolean isMakeOrder() {
        return isMakeOrder;
    }

    @Override
    public boolean isTakeOrder() {
        return isTakeOrder;
    }

    @Override
    public void setMakeOrder() {
        isMakeOrder = true;
    }

    @Override
    public void setTakeOrder() {
        isTakeOrder = true;
    }
}
