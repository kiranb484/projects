import pygame
import random
from pygame.locals import (
    RLEACCEL,
    KEYDOWN,
    K_UP, K_w,
    K_DOWN, K_s,
    K_LEFT, K_a,
    K_RIGHT, K_d,
    K_ESCAPE,
    QUIT,
)

pygame.init()

clock = pygame.time.Clock()

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
BLOCK_SIDE = 50
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

RIGHT = 0
LEFT = 1
DOWN = 2
UP = 3

body = pygame.sprite.Group()
all_sprites = pygame.sprite.Group()


class Blocks(pygame.sprite.Sprite):
    def __init__(self):
        super(Blocks, self).__init__()
        self.surface = pygame.transform.scale(pygame.image.load("green.png").convert(), (BLOCK_SIDE, BLOCK_SIDE))
        # self.surface = pygame.Surface((BLOCK_SIDE, BLOCK_SIDE))
        # self.surface.fill((100, 110, 110))
        self.rect = self.surface.get_rect(
            x=-BLOCK_SIDE,
            y=-BLOCK_SIDE,
        )
        self.speed = BLOCK_SIDE


class Fruits(Blocks):
    def __init__(self):
        super(Fruits, self).__init__()
        self.surface.fill((0, 0, 0))
        self.rect = self.surface.get_rect(
            x=random.randrange(0, SCREEN_WIDTH, BLOCK_SIDE),
            y=random.randrange(0, SCREEN_HEIGHT, BLOCK_SIDE),
        )


class Head(Blocks):
    def __init__(self):
        super(Head, self).__init__()
        self.surface = pygame.transform.scale(pygame.image.load("red.png"), (BLOCK_SIDE, BLOCK_SIDE))
        self.rect.x = self.rect.y = 0
        self.direction = RIGHT


class Snake(pygame.sprite.Sprite):
    def __init__(self):
        super(Snake, self).__init__()
        self.list = []
        new_head = Head()
        self.head = new_head
        self.direction = RIGHT

    def update_direction(self, pressed_keys):
        if pressed_keys[K_UP] or pressed_keys[K_w]:
            self.direction = K_UP - K_RIGHT
        if pressed_keys[K_DOWN] or pressed_keys[K_s]:
            self.direction = K_DOWN - K_RIGHT
        if pressed_keys[K_LEFT] or pressed_keys[K_a]:
            self.direction = K_LEFT - K_RIGHT
        if pressed_keys[K_RIGHT] or pressed_keys[K_d]:
            self.direction = K_RIGHT - K_RIGHT

    def add_block(self):
        new_block = Blocks()
        self.list.append(new_block)

    def update(self):
        head = self.head
        if self.list:
            length = len(self.list)
            index = length - 1
            while index >= 0:
                block_element = self.list[index]
                if index == 0:
                    reference_element = head
                else:
                    reference_element = self.list[index - 1]
                block_element.rect.x = reference_element.rect.x
                block_element.rect.y = reference_element.rect.y
                index -= 1

        if self.direction == UP:
            head.rect.y -= head.speed
        elif self.direction == DOWN:
            head.rect.y += head.speed
        elif self.direction == LEFT:
            head.rect.x -= head.speed
        elif self.direction == RIGHT:
            head.rect.x += head.speed

        if head.rect.x < 0:
            head.rect.x += SCREEN_WIDTH
        elif head.rect.x >= SCREEN_WIDTH:
            head.rect.x = 0
        if head.rect.y < 0:
            head.rect.y += SCREEN_HEIGHT
        elif head.rect.y >= SCREEN_HEIGHT:
            head.rect.y = 0
        # if head.rect.left < 0:
        #     head.rect.left = 0
        # if head.rect.right > SCREEN_WIDTH:
        #     head.rect.right = SCREEN_WIDTH
        # if head.rect.top < 0:
        #     head.rect.top = 0
        # if head.rect.bottom > SCREEN_HEIGHT:
        #     head.rect.bottom = SCREEN_HEIGHT


UPDATE_BODY = pygame.USEREVENT + 1
UPDATE_FRUITS = pygame.USEREVENT + 2
pygame.time.set_timer(UPDATE_BODY, 500)

snake = Snake()
fruit = Fruits()
all_sprites.add(fruit)
all_sprites.add(snake.head)

running = True
while running:
    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                running = False
        elif event.type == QUIT:
            running = False
        elif event.type == UPDATE_BODY:
            snake.update()

    pressed_keys = pygame.key.get_pressed()

    snake.update_direction(pressed_keys)

    screen.fill((255, 255, 255))

    # screen.blit(snake.head.surface, snake.head.rect)
    # for block in snake.list:
    #     screen.blit(block.surface, block.rect)
    # screen.blit(block.surface, block.rect)
    for sprite in all_sprites:
        screen.blit(sprite.surface, sprite.rect)
    if pygame.sprite.spritecollideany(snake.head, body):
        running = False
    if pygame.sprite.collide_rect(snake.head, fruit):
        fruit.kill()
        snake.add_block()
        body.add(snake.list[-1])
        all_sprites.add(snake.list[-1])
        fruit = Fruits()
        while pygame.sprite.spritecollideany(fruit, body):
            fruit.kill()
            fruit = Fruits()
        all_sprites.add(fruit)

    pygame.display.flip()

pygame.quit()
