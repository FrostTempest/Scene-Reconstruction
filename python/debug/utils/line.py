# Paramaterized line, defined by two points


class Line:

    def __init__(self, pt1, pt2):
        self.origin = pt1
        self.direction = (pt2[0] - pt1[0], pt2[1] - pt1[1], pt2[2] - pt1[2])
        self.other = pt2

    def atT(self, t):
        return (self.origin[0] + self.direction[0] * t, self.origin[1] + self.direction[1] * t, self.origin[2] + self.direction[2] * t)
