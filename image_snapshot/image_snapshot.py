import pygame
from pygame.locals import (
    RLEACCEL,
    KEYDOWN,
    K_ESCAPE,
    K_SPACE,
    QUIT,
)

pygame.init()
clock = pygame.time.Clock()

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
BLOCK_SIDE = 10
BORDER_WIDTH = 1

screen = pygame.display.set_mode([SCREEN_WIDTH, SCREEN_HEIGHT])
screen.fill((255, 255, 255))
pygame.image.save(screen, "img.png")


class Block(pygame.sprite.Sprite):
    def __init__(self):
        super(Block, self).__init__()
        self.border_surface = pygame.Surface((BLOCK_SIDE, BLOCK_SIDE))
        self.border_surface.fill((0, 0, 0))
        self.surface = pygame.Surface((BLOCK_SIDE - 2*BORDER_WIDTH, BLOCK_SIDE - 2*BORDER_WIDTH))
        self.color = [125, 125, 125]
        self.border_rect = self.border_surface.get_rect(
            x=0,
            y=0,
        )
        self.rect = self.surface.get_rect()
        self.rect.center = self.border_rect.center
        self.surface.fill(self.color)
        self.index = 0
        self.x_speed = 5
        self.y_speed = 5
        self.multiplier = 1

    def update(self):
        if self.color[self.index] >= 255 or self.color[self.index] <= 0:
            self.index += self.multiplier
            if self.index > 2 or self.index < 0:
                self.multiplier *= -1
                self.index += self.multiplier
        self.color[self.index] += self.multiplier
        # print(self.color)
        # self.surface.fill(self.color)
        self.surface.fill(self.color)
        self.border_rect.x += self.x_speed
        self.border_rect.y += self.y_speed
        if self.border_rect.bottom >= SCREEN_HEIGHT or self.border_rect.top <= 0:
            self.y_speed *= -1
        if self.border_rect.right >= SCREEN_WIDTH or self.border_rect.left <= 0:
            self.x_speed *= -1
        self.rect.center = self.border_rect.center


test = True
player = Block()
running = True
while running:
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
    # screen.fill((255, 255, 255))
    bck_img = pygame.image.load("img.png").convert()
    screen.blit(bck_img, (0, 0))
    # if test:
    #     player.rect.x += 10
    #     pygame.draw.rect(player.surface, (0, 0, 0), player.rect, 2)
    #     test = False
    # pygame.draw.rect(screen, (0, 0, 0), player.rect, 2)
    screen.blit(player.border_surface, player.border_rect)
    screen.blit(player.surface, player.rect)
    player.update()
    pygame.image.save(screen, "img.png")
    pygame.display.flip()
    # clock.tick(30)
pygame.quit()
