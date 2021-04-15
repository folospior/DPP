#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

/**
 * @brief The main namespace for D++ functions. classes and types
 */
namespace dpp {
	/** @brief A 64 bit unsigned value representing many things on discord.
	 * Discord calls the value a 'snowflake' value.
	 */
	typedef uint64_t snowflake;

	/** @brief The managed class is the base class for various types that can
	 * be stored in a cache that are identified by a dpp::snowflake id
	 */
	class managed {
	public:
		/** Unique ID of object */
		snowflake id;
		/** Constructor, initialises id to 0 */
		managed();
		/** Default destructor */
		~managed() = default;
	};

	/** @brief Supported image types for profile pictures */
	enum image_type {
		i_png,
		i_jpg,
		i_gif
	};

	/** @brief Log levels */
	enum loglevel {
		ll_trace = 0,
		ll_debug,
		ll_info,
		ll_warning,
		ll_error,
		ll_critical
	};

	/** @brief Utility helper functions, generally for logging */
	namespace utility {
		/**
		 * @brief Returns urrent date and time
		 * 
		 * @return std::string Current date and time
		 */
		std::string current_date_time();
		/**
		 * @brief Convert a dpp::loglevel enum value to a string
		 * 
		 * @param in log level to convert
		 * @return std::string string form of log level
		 */
		std::string loglevel(dpp::loglevel in);

		/**
		 * @brief Store a 128 bit icon hash (profile picture, server icon etc)
		 * as a 128 bit binary value made of two uint64_t.
		 * Has a constructor to build one from a string, and a method to fetch
		 * the value back in string form.
		 */
		struct iconhash {

			uint64_t first;		//< High 64 bits
			uint64_t second;	//< Low 64 bits

			/**
			 * @brief Construct a new iconcash object
			 */
			iconhash();

			/**
			 * @brief Construct a new iconhash object
			 * 
			 * @param hash String hash to construct from.
			 * Must contain a 32 character hex string.
			 * 
			 * @throws std::length_error if the provided
			 * string is not exactly 32 characters long.
			 */
			iconhash(const std::string &hash);

			/**
			 * @brief Assign from std::string
			 * 
			 * @param assignment string to assign from.
			 * 
			 * @throws std::length_error if the provided
			 * string is not exactly 32 characters long.
			 */
			iconhash& operator=(const std::string &assignment);

			/**
			 * @brief Change value of iconhash object
			 * 
			 * @param hash String hash to change to.
			 * Must contain a 32 character hex string.
			 * 
			 * @throws std::length_error if the provided
			 * string is not exactly 32 characters long.
			 */
			void set(const std::string &hash);

			/**
			 * @brief Convert iconhash back to 32 character
			 * string value.
			 * 
			 * @return std::string Hash value 
			 */
			std::string to_string() const;
		};

		/**
		 * @brief Returns true if D++ was built with voice support
		 * 
		 * @return bool True if voice support is compiled in (libsodium/libopus) 
		 */
		bool has_voice();

		/**
		 * @brief A class used to represent an uptime in hours, minutes,
		 * seconds and days, with helper functions to convert from time_t
		 * and display as a string.
		 */
		struct uptime {
			uint16_t days;	//< Number of days
			uint8_t hours;	//< Number of hours
			uint8_t mins;	//< Number of minutes
			uint8_t secs;	//< Number of seconds

			/**
			 * @brief Construct a new uptime object
			 */
			uptime();

			/**
			 * @brief Construct a new uptime object
			 * 
			 * @param diff A time_t to initialise the object from
			 */
			uptime(time_t diff);

			/**
			 * @brief Get uptime as string
			 * 
			 * @return std::string Uptime as string
			 */
			std::string to_string();
		};

		void debug_dump(uint8_t* data, size_t length);
	};

};

#include <dpp/role.h>
#include <dpp/user.h>
#include <dpp/channel.h>
#include <dpp/guild.h>
#include <dpp/invite.h>
#include <dpp/dtemplate.h>
#include <dpp/emoji.h>
#include <dpp/ban.h>
#include <dpp/prune.h>
#include <dpp/voiceregion.h>
#include <dpp/integration.h>
#include <dpp/webhook.h>
#include <dpp/voicestate.h>
#include <dpp/presence.h>
#include <dpp/intents.h>
