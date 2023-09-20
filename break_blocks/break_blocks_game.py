import pygame
from pygame.locals import (
    KEYDOWN,
    QUIT,
    K_ESCAPE,
    K_LEFT,
    K_RIGHT,
)

pygame.init()

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
BALL_SIDE = 10
PLAYER_WIDTH = 80
PLAYER_HEIGHT = 10

all_sprites = pygame.sprite.Group()


class Ball(pygame.sprite.Sprite):
    def __init__(self):
        super(Ball, self).__init__()
        self.surface = pygame.Surface((BALL_SIDE, BALL_SIDE))
        self.surface.fill((255, 255, 255))
        self.rect = self.surface.get_rect()
        self.x_speed = 5
        self.y_speed = 4

    def update(self):
        self.rect.x += self.x_speed
        self.rect.y += self.y_speed

        if self.rect.right > SCREEN_WIDTH or self.rect.left < 0:
            self.x_speed = -self.x_speed
        if self.rect.bottom > SCREEN_HEIGHT or self.rect.top < 0:
            self.y_speed = -self.y_speed


class Player(pygame.sprite.Sprite):
    def __init__(self):
        super(Player, self).__init__()
        self.surface = pygame.Surface((PLAYER_WIDTH, PLAYER_HEIGHT))
        self.surface.fill((255, 0, 0))
        self.rect = self.surface.get_rect(
            center=(
                SCREEN_WIDTH/2,
                SCREEN_HEIGHT - (2 * PLAYER_HEIGHT),
            )
        )

clock = pygame.time.Clock()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

ball = Ball()
player = Player()
all_sprites.add(ball)
all_sprites.add(player)
running = True
while running:
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
        if event.type == pygame.QUIT:
            running = False

    screen.fill((30, 30, 30))
    for sprite in all_sprites:
        screen.blit(sprite.surface, sprite.rect)
    pygame.display.flip()
    ball.update()
    clock.tick(60)

pygame.quit()