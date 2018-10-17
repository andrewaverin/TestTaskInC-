#include "main.h"

int random(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

std::vector<std::shared_ptr<Figure>> GenerateVectorFigure(int quantity)
{
	std::vector<std::shared_ptr<Figure>> vecFigure;

	for (int i = 0; i < quantity; i++)
	{
		int figure_number = random(0, 2);

		switch (figure_number)
		{
			case 0:
				vecFigure.push_back(std::shared_ptr<Figure>(std::make_shared<Ellipse>(random(1, 5), random(1, 7))));
				break;
			case 1:
				vecFigure.push_back(std::shared_ptr<Figure>(std::make_shared<Circle>(random(1, 10))));
				break;
			case 2:
				vecFigure.push_back(std::shared_ptr<Figure>(std::make_shared<Helix>(random(1, 10), 5)));
				break;

			default:
			break;
		}
	}

	return vecFigure;
}

void SplitFiguresIntoCircles(std::vector<std::shared_ptr<Figure>> &vecFigure, std::vector<std::shared_ptr<Circle>> &vecCircle)
{
	for (auto p = vecFigure.begin(); p != vecFigure.end(); p++)
		if ((*p)->WhoAmI() == Circle::CIRCLE_ID)
		{
			std::shared_ptr<Circle> tmp = std::make_shared<Circle>();
			tmp = std::dynamic_pointer_cast<Circle>(*p);
			vecCircle.push_back(tmp);
		}
}

double GetSumRadiusCircles(const std::vector<std::shared_ptr<Circle>> vecCircle)
{
	double radiusSum = 0.0;

	#pragma omp for	
		for (int i = 0; i < vecCircle.size(); i++)
			radiusSum += vecCircle[i]->GetRadius();

	return radiusSum;
}

int main(int argc, char** argv)
{
	srand(time(0));

	std::vector<std::shared_ptr<Figure>> figures = GenerateVectorFigure(15);
	std::vector<std::shared_ptr<Circle>> circles;
	SplitFiguresIntoCircles(figures, circles);

	std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> lCricle, std::shared_ptr<Circle> rCircle)
	{
		return lCricle->GetRadius() < rCircle->GetRadius();
	});

	std::cout << "Sum circles radius: " << GetSumRadiusCircles(circles) << std::endl;

	return 0;
}
