import matplotlib.pyplot as plt

def plot_trapezium(a, b, c, d):
    plt.plot([a, c], [b, b], 'b')  # plot top base
    plt.plot([a, a], [b, 0], 'b')  # plot left side
    plt.plot([c, c], [d, 0], 'b')  # plot right side
    plt.plot([a, c], [0, 0], 'b')  # plot bottom base

def plot_trapeziums_from_string(s):
    lines = s.split('\n')
    for line in lines:
        a, b, c, d = map(float, line.split())
        plot_trapezium(a, b, c, d)

    plt.xlim([0, 800])
    plt.ylim([0, 50])
    plt.gca().set_aspect('equal', adjustable='box')
    plt.savefig('trapeziums.png')

# Example usage:
s = """712 3 761 20
59 23 87 11
506 15 534 7
309 50 321 4
751 25 771 33
169 5 179 14
435 1 448 36
348 32 361 50
356 10 359 29
244 2 257 11"""
plot_trapeziums_from_string(s)
