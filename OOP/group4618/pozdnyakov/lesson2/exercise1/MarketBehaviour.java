package group4618.pozdnyakov.lesson2.exercise1;

import java.util.List;

public interface MarketBehaviour {
    void acceptToMarket(Actor actor);

    void releaseFromMarket(List<Actor> actors);

    void update();
}
