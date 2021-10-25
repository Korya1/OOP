#pragma once
class Robot {

public:
	Robot() = default;

	void move(std::string& direction)
	{
		if (!direction.compare("up"))
			y++;
		else if (!direction.compare("down"))
			y--;
		else if (!direction.compare("right"))
			x++;
		else if (!direction.compare("left"))
			x--;
		else
			throw IllegalCommand(*this);

		if (x > MAX || y > MAX)
			throw OffTheField(*this);
	};

	const size_t getX() const { return x; }
	const size_t getY() const { return y; }

private:
	static const size_t MAX{ 10 };
	size_t x{};
	size_t y{};

};


class RobotsException {
public:
	RobotsException(const Robot& robot)
		:
		reason{ "" }, ex{ robot.getX() }, ey{ robot.getY() } {};

	friend std::ostream& operator<<(std::ostream&, const RobotsException&);
protected:
	std::string reason;
	size_t ex;
	size_t ey;
};

std::ostream& operator<<(std::ostream& out, const RobotsException& exc_obj) {

	out << "What's happened: " << exc_obj.reason << std::endl;

	return out;
}

class OffTheField : public RobotsException {
public:
	OffTheField(const Robot& robot) : RobotsException(robot) {
		reason = "Off the Field";
	}
};

class IllegalCommand : public RobotsException {
public:
	IllegalCommand(const Robot& robot) : RobotsException(robot) {
		reason = "Illegal command";
	};
};
