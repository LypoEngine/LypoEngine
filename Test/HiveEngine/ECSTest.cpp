//
// Created by samuel on 10/9/24.
//

#include <gtest/gtest.h>

#include "scene/ECS.h"
#include "scene/query_builder.h"
#include "scene/Registry.h"

class ECSTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		hive::ECS::init();
	}
	void TearDown() override
	{
		hive::ECS::shutdown();
	}
};
TEST_F(ECSTest, ShouldCreateEntity)
{
	auto registry = hive::ECS::getCurrentRegistry();
	auto entity = registry->createEntity();
	EXPECT_NE(&entity, nullptr);
}

TEST_F(ECSTest, ShouldAddComponent)
{
	auto registry = hive::ECS::getCurrentRegistry();
	auto entity = hive::ECS::createEntity();

	struct Player{};
	hive::ECS::addComponent<Player>(entity);

	EXPECT_TRUE(registry->hasComponent<Player>(entity));
}


class TestSystem : public hive::System
{
public:
	void init() override
	{
		is_init = true;
	}

	void update(float deltaTime) override
	{
		is_updated = true;
	}

	bool is_init = false;
	bool is_updated = false;

};
TEST_F(ECSTest, SystemShouldInitWhenRegister)
{
	TestSystem *test_system = new TestSystem();
	hive::ECS::registerSystem(test_system, "TestSystem");

	EXPECT_TRUE(test_system->is_init);
}

TEST_F(ECSTest, SystemShouldUpdate)
{
	TestSystem *test_system = new TestSystem();

	hive::ECS::registerSystem(test_system, "TestSystem");

	hive::ECS::updateSystems(0);

	EXPECT_TRUE(test_system->is_updated);
}

TEST_F(ECSTest, SystemShouldBeRemoved)
{
	TestSystem *test_system = new TestSystem();

	hive::ECS::registerSystem(test_system, "TestSystem");
	hive::ECS::removeSystem("TestSystem");

	hive::ECS::updateSystems(0);

	EXPECT_TRUE(test_system->is_init);
	EXPECT_FALSE(test_system->is_updated);
}

TEST_F(ECSTest, SystemShouldNotUpdateIfDisabled)
{
	TestSystem *test_system = new TestSystem();

	hive::ECS::registerSystem(test_system, "TestSystem");

	test_system->is_active = false;

	hive::ECS::updateSystems(0);

	EXPECT_TRUE(test_system->is_init);
	EXPECT_FALSE(test_system->is_updated);
}


TEST_F(ECSTest, QueryBuilderShouldFetchCorrectEntity)
{

	auto entity = hive::ECS::createEntity();
	auto entity2 = hive::ECS::createEntity();

	struct Player
	{
		int id;
	};

	struct Enemy
	{

	};
	hive::ECS::addComponent<Player>(entity, 20);
	hive::ECS::addComponent<Player>(entity2, 33);

	auto query = hive::QueryBuilder<Player>();

	auto it = query.each().begin();
	auto [e1, p1] = *it;
	it.operator++();

	auto [e2, p2] = *it;


	EXPECT_TRUE(p1.id == 33);
	EXPECT_TRUE(p2.id == 20);
}


TEST_F(ECSTest, QueryBuilderShouldFetchWithMultipleComponent)
{

	auto entity = hive::ECS::createEntity();
	auto entity2 = hive::ECS::createEntity();

	struct Player
	{
		int id;
	};

	struct Enemy
	{

	};
	hive::ECS::addComponent<Player>(entity, 20);
	hive::ECS::addComponent<Player>(entity2, 33);
	hive::ECS::addComponent<Enemy>(entity2);

	auto query = hive::QueryBuilder<Player, Enemy>();

	auto it = query.each().begin();
	auto [e1, p1] = *it;
	it.operator++();

	EXPECT_EQ(it, query.each().end());
	EXPECT_TRUE(p1.id == 33);
}
