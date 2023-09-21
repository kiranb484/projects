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
BLOCK_WIDTH = 25
BLOCK_HEIGHT = 25
BALL_SIDE = 10
PLAYER_WIDTH = 80
PLAYER_HEIGHT = 10
COLLISION_TOLERANCE = 10

all_sprites = pygame.sprite.Group()
balls_group = pygame.sprite.Group()
blocks_group = pygame.sprite.Group()


class Ball(pygame.sprite.Sprite):
    def __init__(self):
        super(Ball, self).__init__()
        self.surface = pygame.Surface((BALL_SIDE, BALL_SIDE))
        self.surface.fill((255, 255, 255))
        self.rect = self.surface.get_rect(
            center=(
                SCREEN_WIDTH/2,
                SCREEN_HEIGHT - ((2.5*PLAYER_HEIGHT) + BALL_SIDE/2)
            )
        )
        self.x_speed = 3
        self.y_speed = 3

    def update(self):
        self.rect.x += self.x_speed
        self.rect.y += self.y_speed

        if self.rect.right > SCREEN_WIDTH or self.rect.left < 0:
            self.x_speed *= -1
        if self.rect.top < 0:
            self.y_speed *= -1
        if self.rect.top > SCREEN_HEIGHT:
            self.kill()


class Player(pygame.sprite.Sprite):
    def __init__(self):
        super(Player, self).__init__()
        self.surface = pygame.Surface((PLAYER_WIDTH, PLAYER_HEIGHT))
        self.surface.fill((255, 0, 0))
        self.speed = 5
        self.rect = self.surface.get_rect(
            center=(
                SCREEN_WIDTH/2,
                SCREEN_HEIGHT - (2 * PLAYER_HEIGHT),
            )
        )

    def update(self, pressed_keys):
        if pressed_keys[K_LEFT]:
            self.rect.x -= self.speed
        if pressed_keys[K_RIGHT]:
            self.rect.x += self.speed

        if self.rect.left < 0:
            self.rect.left = 0
        if self.rect.right > SCREEN_WIDTH:
            self.rect.right = SCREEN_WIDTH


class Block(pygame.sprite.Sprite):
    def __init__(self):
        super(Block, self).__init__()
        self.surface = pygame.Surface((BLOCK_WIDTH, BLOCK_HEIGHT))
        self.surface.fill((0, 0, 255))
        self.rect = self.surface.get_rect(
            center=(
                SCREEN_WIDTH/2,
                SCREEN_HEIGHT/2,
            )
        )


def place_blocks():
    rows = 5 #(SCREEN_HEIGHT/BLOCK_HEIGHT)/2
    cols = (SCREEN_WIDTH/BLOCK_WIDTH)/2 - 1

    starting_x = BLOCK_WIDTH
    temp_x = starting_x
    starting_y = BLOCK_HEIGHT
    temp_y = starting_y

    for i in range(int(rows)):
        for j in range(int(cols)):
            new_block = Block()
            blocks_group.add(new_block)
            all_sprites.add(new_block)
            new_block.rect.x = temp_x
            new_block.rect.y = temp_y
            temp_x += (2*BLOCK_WIDTH)
        temp_x = starting_x
        temp_y += (2*BLOCK_HEIGHT)


clock = pygame.time.Clock()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

ball = Ball()
player = Player()
#block = Block()
all_sprites.add(ball)
all_sprites.add(player)
#all_sprites.add(block)
balls_group.add(ball)
#blocks_group.add(block)
running = True
place_blocks()
while running:
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
        if event.type == pygame.QUIT:
            running = False

    pressed_keys = pygame.key.get_pressed()
    screen.fill((30, 30, 30))
    for sprite in all_sprites:
        screen.blit(sprite.surface, sprite.rect)

    player.update(pressed_keys)
    for ball in balls_group:
        ball.update()
        if ball.rect.colliderect(player.rect):
            if abs(ball.rect.bottom - player.rect.top) < COLLISION_TOLERANCE:
                ball.y_speed *= -1
        for block_element in blocks_group:
            if ball.rect.colliderect(block_element.rect):
                if abs(ball.rect.bottom - block_element.rect.top) < COLLISION_TOLERANCE:
                    ball.y_speed *= -1
                if abs(ball.rect.top - block_element.rect.bottom) < COLLISION_TOLERANCE:
                    ball.y_speed *= -1
                if abs(ball.rect.left - block_element.rect.right) < COLLISION_TOLERANCE:
                    ball.x_speed *= -1
                if abs(ball.rect.right - block_element.rect.left) < COLLISION_TOLERANCE:
                    ball.x_speed *= -1
                block_element.kill()
    if len(balls_group.sprites()) == 0:
        running = False

    pygame.display.flip()
    clock.tick(60)

pygame.quit()