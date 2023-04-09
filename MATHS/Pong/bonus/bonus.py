import sys, pygame
from random import randint as rd
import numpy as np
from colorama import Fore, Style

pygame.init()

x, y = 750, 500
size = width, height = 1500, 1000
black = 0, 0, 0
white = 255, 255, 255
taille_h, taille_w = 20, 100
p_barr1, p_barr2 = 30, width - taille_w + 30
pos_barre = [450, 450]
dir_ball = [1 + (rd(0, 1) * -2), 1 + rd(0, 1) * -2]
radius = 20
FPS = 400
fpsClock = pygame.time.Clock()

screen = pygame.display.set_mode(size)

screen.fill(white)

barr1 = pygame.rect.Rect(p_barr1, pos_barre[0], taille_h, taille_w)
barr2 = pygame.rect.Rect(p_barr2, pos_barre[1], taille_h, taille_w)
ball = [x, y]

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()

    keys=pygame.key.get_pressed()
    if keys[pygame.K_UP] and barr2.top > 0:
        barr2 = barr2.move(0, -1)
    if keys[pygame.K_DOWN] and barr2.bottom < height:
        barr2 = barr2.move(0, 1)
    if keys[pygame.K_z] and barr1.top > 0:
        barr1 = barr1.move(0, -1)
    if keys[pygame.K_s] and barr1.bottom < height:
        barr1 = barr1.move(0, 1)

    ball = np.add(ball, dir_ball)
    if ball[0]-radius < 0 or ball[0]+radius > width:
        str = "\nplayer 2 win\n" if ball[0]-radius < 0 else "\nplayer 1 win\n"
        print(Fore.GREEN + str + Style.RESET_ALL)
        break
    if (barr1.left > ball[0]-radius and barr1.top < ball[1] < barr1.bottom) or (barr2.right < ball[0]+radius and barr2.top < ball[1] < barr2.bottom):
        dir_ball[0] = -dir_ball[0]
    if ball[1]-radius < 0 or ball[1]+radius > height:
        dir_ball[1] = -dir_ball[1]

    screen.fill(white)
    pygame.draw.rect(screen, black, barr1)
    pygame.draw.rect(screen, black, barr2)
    pygame.draw.circle(screen, black, (ball[0], ball[1]), radius)
    pygame.display.flip()
    pygame.display.update()
    fpsClock.tick(FPS)
