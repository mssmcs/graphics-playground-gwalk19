#include "graphics.h"

using namespace std;
using namespace mssm;

class Button {
public:
    int width;
    int height;
    Vec2d pos;

    bool mouseOverButton(Vec2d mp) {
        if (pos.x < mp.x && mp.x < pos.x + width &&
            pos.y < mp.y && mp.y < pos.y + height) {
            return true;
        }
        return false;
    }

    bool clicked(Graphics& g, Vec2d mp) {
        if (mouseOverButton(mp) && g.isMousePressed(MouseButton::Left)) {
            return true;
        }
        return false;
    }

    void draw(Graphics& g, Vec2d mp) {
        Color fillColor;
        if (mouseOverButton(mp)) {
            fillColor = RED;
        } else {
            fillColor = GREEN;
        }
        g.rect(pos, width, height, fillColor, fillColor);
    }
};

int main() {
    Graphics g("Button of DOOM!!!", 1024, 768);

    Button button;
    button.width = 300;
    button.height = 150;
    button.pos = {g.width()/2 - button.width/2, g.height()/2 - button.height/2};

    while (g.draw()) {
        Vec2d mp = g.mousePos();

        button.draw(g, mp);

        if (button.clicked(g, mp)) {
            break;
        }
    }

    return 0;
}
